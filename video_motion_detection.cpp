
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture videoCapture(0); // Open video camera
    if (!videoCapture.isOpened()) {
        std::cerr << "ERROR: Could not open video camera" << std::endl;
        return -1;
    }

    double fps = videoCapture.get(cv::CAP_PROP_FPS); // Get the frame rate of the camera

    int fourcc = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    cv::Size frameSize(static_cast<int>(videoCapture.get(cv::CAP_PROP_FRAME_WIDTH)),
                       static_cast<int>(videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT)));

    // Create videoWriter object to write the video
    cv::VideoWriter videoWriter("output.avi", fourcc, fps, frameSize, true);

    if (!videoWriter.isOpened()) {
        std::cerr << "ERROR: Could not open the output video file for write" << std::endl;
        return -1;
    }

    cv::Mat prevFrame, currFrame, frameDiff, shiftedFrame;  // Declare all matrices for storing frames
    bool isFirstFrame = true;

    int frameCount = 0;
    while (frameCount < (15 * fps)) { // Process for 15 seconds
        videoCapture >> currFrame;
        if (currFrame.empty()) {
            std::cerr << "ERROR: Could not read video frame" << std::endl;
            break;
        }

        cv::cvtColor(currFrame, currFrame, cv::COLOR_BGR2GRAY); // Convert to grayscale

        if (isFirstFrame) {
            currFrame.copyTo(prevFrame);
            isFirstFrame = false;
            continue; // Skip the rest of the loop
        }

        // Subtract the current frame from the previous frame
        cv::absdiff(currFrame, prevFrame, frameDiff);

        frameDiff.forEach<uchar>([](uchar &pixel, const int * position) -> void {
            if (pixel < 128) pixel = 128 - pixel; // Darker if the new frame is darker than the previous
            else if (pixel > 128) pixel = pixel + 128; // Brighter if the new frame is brighter
        });

        // Display the resulting frame
        cv::imshow("Frame Difference", frameDiff);

        // Write the frame into the file 'output.avi'
        videoWriter.write(frameDiff);

        // Update previous frame
        currFrame.copyTo(prevFrame);

        char key = static_cast<char>(cv::waitKey(1));
        if (key == 'q' || key == 27) { // 'q' or ESC to quit
            break;
        }

        frameCount++;
    }

    videoCapture.release();
    videoWriter.release();
    cv::destroyAllWindows();

    return 0;
}
