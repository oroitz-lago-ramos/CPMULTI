#ifndef IMAGE_SPLITTER_H
#define IMAGE_SPLITTER_H

#include <opencv2/opencv.hpp>
#include <vector>

class ImageSplitter {
public:
    // Méthode statique pour diviser l'image en quatre parties
    static std::vector<cv::Mat> splitImage(const cv::Mat& inputImage);

    // Order is tL, tR, bL, bR
    static cv::Mat mergeImage(const std::vector<cv::Mat>& subImages);
};

#endif // IMAGE_SPLITTER_H
