//
// Created by Oroitz on 23/01/2025.
//
#include "../include/ImageLoader.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>

cv::Mat ImageLoader::loadImage(const std::string& filepath) {
    cv::Mat image = cv::imread(filepath);
    if (image.empty()) {
        std::cerr << "Error loading image: " << filepath << std::endl;
    }
    return image;
}

void ImageLoader::saveImage(const cv::Mat& image, const std::string& filepath) {
    if (!cv::imwrite(filepath, image)) {
        std::cerr << "Erreur : Impossible de sauvegarder l'image dans " << filepath << std::endl;
    }
}
