//
// Created by Aashka Desai on 2/08/24.
//
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {

    // Load the image
    cv::Mat image = cv::imread("/Users/aashkadesai/CLionProjects/AdvanceCV/HW_01/kitty.jpeg", cv::IMREAD_COLOR);

    cv::imshow("Original Image", image);  // Display the original image.

    cv::Mat blurredImage; // Apply a strong Gaussian blur to the image.
    cv::GaussianBlur(image, blurredImage, cv::Size(81, 81), 0);

    cv::imshow("Blurred Image", blurredImage);   // Display the blurred image.
    cv::imwrite("/Users/aashkadesai/CLionProjects/AdvanceCV/blurred_kitty.jpg", blurredImage);

    cv::waitKey(0);

    return 0;
}
