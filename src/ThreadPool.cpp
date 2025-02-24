#include "../include/ThreadPool.h"
#include "../include/ImageSplitter.h"
#include <opencv2/core/mat.hpp>
#include <thread>
#include <vector>
#include <functional>

cv::Mat ThreadPool::processImage(const cv::Mat& image, std::function<cv::Mat(const cv::Mat&)> filterFunction) {
    std::vector<cv::Mat> subImages = ImageSplitter::splitImage(image);
    std::vector<cv::Mat> processedSubImages(subImages.size());

    std::vector<std::thread> threads;
    for (size_t i = 0; i < subImages.size(); ++i) {
        threads.emplace_back([&, i]() {
            processedSubImages[i] = filterFunction(subImages[i]);
            cv::imwrite("../data/Image Split/output" + std::to_string(i) + ".jpg", processedSubImages[i]);
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return ImageSplitter::mergeImage(processedSubImages);
}