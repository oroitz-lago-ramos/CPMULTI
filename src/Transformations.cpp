//
// Created by Oroitz on 23/01/2025.
//

#include "../include/Transformations.h"

cv::Mat rotateImageFromCenter(const cv::Mat& image, double angle) {
    cv::Mat result;
    cv::Point2f center(image.cols / 2, image.rows / 2);
    cv::Mat rotation_matrix = cv::getRotationMatrix2D(center, angle, 1.0);
    cv::warpAffine(image, result, rotation_matrix, image.size());
    return result;
}