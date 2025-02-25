//
// Created by Lyes- on 08/02/2025.
//

#ifndef MENUS_H
#define MENUS_H
#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/mat.hpp>
#include "PerformanceAnalyzer.h"

class Menus{
    public:
    static void launchMenuChoiceThread(const cv::Mat &image, PerformanceAnalyzer& performance);

    static void launchMenu(const cv::Mat &image, bool useThread, PerformanceAnalyzer& performance);

    static void launchMenuFilters(const cv::Mat &image, bool useThread, PerformanceAnalyzer& performance);

    static void launchMenuTransformation(const cv::Mat &image, bool useThread, PerformanceAnalyzer& performance);
};


#endif //MENUS_H
