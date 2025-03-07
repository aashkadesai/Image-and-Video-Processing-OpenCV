//
// Created by Aashka Desai on 1/23/24.
//
#include <opencv2/opencv.hpp>

int main() {
    // Load the image
    cv::Mat image = cv::imread("/Users/aashkadesai/CLionProjects/AdvanceCV/HW_01/kitty.jpeg");

    // Rotate the image by 30 degrees counterclockwise
    cv::Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, -30, 1);
    cv::Mat rotatedImage;
    cv::warpAffine(image, rotatedImage, rotationMatrix, image.size());

    // Calculate the new size while maintaining aspect ratio (height <=900)
    double aspectRatio = rotatedImage.cols / static_cast<double>(rotatedImage.rows);
    int newHeight = std::min(900, rotatedImage.rows); // Ensure height is <= 900
    int newWidth = static_cast<int>(newHeight * aspectRatio);

    cv::Mat resizedImage;
    cv::resize(rotatedImage, resizedImage, cv::Size(newWidth, newHeight), 0, 0,
               cv::INTER_LINEAR);

    cv::imshow("Original Image", image);   // Display the original image
    cv::imshow("Rotated and Resized Image", resizedImage);   // Display the rotated and resized image
    cv::imwrite("/Users/aashkadesai/CLionProjects/AdvanceCV/HW_01/resized_kitty.jpg", resizedImage);
    cv::waitKey(0);
    return 0;
}
