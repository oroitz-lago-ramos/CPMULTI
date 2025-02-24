//
// Created by Lyes- on 08/02/2025.
//

#ifndef MENUS_H
#define MENUS_H
#include <opencv2/core/cvstd.hpp>

class Menus{
    public:
        static void launchMenu(const cv::Mat &image);
        static void launchMenuFilters(const cv::Mat &image);
        static void launchMenuTransformation(const cv::Mat &image);
};


#endif //MENUS_H
