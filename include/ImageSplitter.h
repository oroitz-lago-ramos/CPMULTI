#ifndef IMAGE_SPLITTER_H
#define IMAGE_SPLITTER_H

#include <opencv2/opencv.hpp>
#include <vector>

class ImageSplitter {
public:
    // Méthode statique pour diviser l'image en quatre parties
    static std::vector<cv::Mat> splitImage(const cv::Mat& inputImage);
};

#endif // IMAGE_SPLITTER_H
