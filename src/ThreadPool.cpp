#include "../include/ThreadPool.h"
#include "../include/ImageSplitter.h"
#include "../include/PerformanceAnalyzer.h"
#include <opencv2/core/mat.hpp>
#include <thread>
#include <vector>
#include <functional>

cv::Mat ThreadPool::processImage(const cv::Mat& image, const std::function<cv::Mat(const cv::Mat&)>& filterFunction, PerformanceAnalyzer& performanceAnalyzer) {
    performanceAnalyzer.start("Image Splitting");
    std::vector<cv::Mat> subImages = ImageSplitter::splitImage(image);
    performanceAnalyzer.stop("Image Splitting");

    performanceAnalyzer.start("Thread Pool Processing");

    std::vector<cv::Mat> processedSubImages(subImages.size());

    std::vector<std::thread> threads;

    for (size_t i = 0; i < subImages.size(); ++i) {
        threads.emplace_back([&, i]() {
            performanceAnalyzer.start("Filtering Sub Image " + std::to_string(i) + " in the " + std::to_string(i) + "th thread");
            processedSubImages[i] = filterFunction(subImages[i]);
            performanceAnalyzer.stop("Filtering Sub Image " + std::to_string(i) + " in the " + std::to_string(i) + "th thread");
        });
    }

    performanceAnalyzer.start("Joining Threads");
    for (auto& thread : threads) {
        thread.join();
    }
    performanceAnalyzer.stop("Joining Threads");

    performanceAnalyzer.stop("Thread Pool Processing");
    return ImageSplitter::mergeImage(processedSubImages);
}