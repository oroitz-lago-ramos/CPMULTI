#ifndef THREADPOOL_H
#define THREADPOOL_H


#include <functional>
#include <opencv2/core/mat.hpp>
#include "filters.h"
#include "PerformanceAnalyzer.h"

class ThreadPool {
public:
    static cv::Mat processImage(const cv::Mat& image, const std::function<cv::Mat(const cv::Mat&)>& filterFunction, PerformanceAnalyzer& performanceAnalyzer);
};

#endif //THREADPOOL_H