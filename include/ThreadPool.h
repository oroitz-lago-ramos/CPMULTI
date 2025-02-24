#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <functional>
#include <opencv2/core/mat.hpp>
#include "filters.h"

class ThreadPool {
public:
    ThreadPool() = default;
    cv::Mat processImage(const cv::Mat& image, std::function<cv::Mat(const cv::Mat&)> filterFunction, PerformanceAnalyzer& performanceAnalyzer);
};

#endif //THREADPOOL_H