#include "../include/ImageSplitter.h"

// Méthode statique pour diviser l'image en quatre parties
std::vector<cv::Mat> ImageSplitter::splitImage(const cv::Mat& inputImage) {
    int width = inputImage.cols;
    int height = inputImage.rows;

    // Définir les rectangles pour chaque section
    cv::Rect topLeft(0, 0, width / 2, height / 2);
    cv::Rect topRight(width / 2, 0, width / 2, height / 2);
    cv::Rect bottomLeft(0, height / 2, width / 2, height / 2);
    cv::Rect bottomRight(width / 2, height / 2, width / 2, height / 2);

    // Extraire et stocker les sous-images
    std::vector<cv::Mat> subImages = {
        inputImage(topLeft),
        inputImage(topRight),
        inputImage(bottomLeft),
        inputImage(bottomRight)
    };

    return subImages;
}
