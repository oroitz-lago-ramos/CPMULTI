//
// Created by Oroitz on 23/01/2025.
//
#include "../include/Filters.h"

#include <opencv2/core/mat.hpp>

cv::Mat Filters::applyGaussianBlur(const cv::Mat& image, cv::Size kernelSize, double sigmaX) {
    cv::Mat result;
    cv::GaussianBlur(image, result, cv::Size(5, 5), 0);
    return result;

}

cv::Mat Filters::applyMedianFilter(const cv::Mat& image, int kernelSize) {
    cv::Mat result;
    cv::medianBlur(image, result, kernelSize);
    return result;
}

cv::Mat Filters::applyCannyEdgeDetection(const cv::Mat& image, double threshold1, double threshold2) {
    cv::Mat result;
    // This Put on another function
    cv::cvtColor(image, result, cv::COLOR_BGR2GRAY);  // Convertir en niveaux de gris
    cv::Canny(result, result, 100, 200);  // Détection des bords
    return result;
}

cv::Mat Filters::applyInvertColors(const cv::Mat &image) {
    cv::Mat result;
    cv::bitwise_not(image, result);
    return result;
}
