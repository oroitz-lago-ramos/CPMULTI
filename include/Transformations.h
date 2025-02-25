//
// Created by Oroitz on 23/01/2025.
//

#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <opencv2/opencv.hpp>

class Transformations {
    public:
    static cv::Mat rotateImageFromCenter(const cv::Mat &image);
    static cv::Mat fourier(const cv::Mat& image);
};
#endif //TRANSFORMATIONS_H
