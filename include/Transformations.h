//
// Created by Oroitz on 23/01/2025.
//

#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <opencv2/opencv.hpp>

class Transformations {
public:
    static cv::Mat rotateImageFromCenter(const cv::Mat& image, double angle);
};
#endif //TRANSFORMATIONS_H
