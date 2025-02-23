//
// Created by Lyes- on 08/02/2025.
//

#ifndef MENUS_H
#define MENUS_H
#include <opencv2/core/cvstd.hpp>

class Menus{
    public:

    static void launchMenu(const std::string &imagePath);
    static void launchMenuFilters(const std::string& imagePath);
    static void launchMenuTransformation(const std::string& imagePath);
};


#endif //MENUS_H
