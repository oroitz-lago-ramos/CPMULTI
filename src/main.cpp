#include <opencv2/opencv.hpp>
#include <iostream>
#include "../include/ImageLoader.h"
#include "../include/Filters.h"
#include "../include/Transformations.h"
#include "../include/ImageSplitter.h"
#include "../include/PerformanceAnalyzer.h"

int main() {
    std::string inputPath = "../data/input/photo.png";
    PerformanceAnalyzer performance;
    // Load image
    performance.start("Loading Image");
    cv::Mat image = ImageLoader::loadImage(inputPath);
    if (image.empty()) {
        std::cerr << "Error on loading Image." << std::endl;
        return -1;
    }
    performance.stop("Loading Image");
    performance.printResults();
    return 0;
}
