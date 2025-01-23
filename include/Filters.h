//
// Created by Oroitz on 23/01/2025.
//

#ifndef FILTERS_H
#define FILTERS_H

#include <opencv2/opencv.hpp>

class Filters {
    public:
    static cv::Mat applyGaussianBlur(const cv::Mat& image, cv::Size kernelSize, double sigmaX);
    static cv::Mat applyMedianFilter(const cv::Mat& image, int kernelSize);
    static cv::Mat applyCannyEdgeDetection(const cv::Mat& image, double threshold1, double threshold2);
    static cv::Mat applyInvertColors(const cv::Mat& image);
};

#endif //FILTERS_H
