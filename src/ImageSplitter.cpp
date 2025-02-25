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

cv::Mat ImageSplitter::mergeImage(const std::vector<cv::Mat>& subImages) {
    if (subImages.size() != 4) {
        throw std::runtime_error("mergeImage needs 4 images.");
    }

    int subWidth = subImages[0].cols;
    int subHeight = subImages[0].rows;
    int width = subWidth * 2;
    int height = subHeight * 2;

    cv::Mat mergedImage(height, width, subImages[0].type());

    subImages[0].copyTo(mergedImage(cv::Rect(0, 0, subWidth, subHeight)));                // top-left
    subImages[1].copyTo(mergedImage(cv::Rect(subWidth, 0, subWidth, subHeight)));           // top-right
    subImages[2].copyTo(mergedImage(cv::Rect(0, subHeight, subWidth, subHeight)));          // bottom-left
    subImages[3].copyTo(mergedImage(cv::Rect(subWidth, subHeight, subWidth, subHeight)));   // bottom-right

    return mergedImage;
}