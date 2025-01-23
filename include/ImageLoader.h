//
// Created by Oroitz on 23/01/2025.
//

#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include <opencv2/core/mat.hpp>


class ImageLoader {
public:
    static cv::Mat loadImage(const std::string& filepath);
    static void saveImage(const cv::Mat& image, const std::string& filepath);
};

#endif //IMAGELOADER_H
