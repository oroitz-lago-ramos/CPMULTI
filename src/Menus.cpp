//
// Created by Lyes- on 08/02/2025.
//


#include "../include/Menus.h"
#include "../include/Filters.h"
#include "../include/Transformations.h"
#include "../include/ImageLoader.h"
#include <iostream>
#include <cstdlib>
using namespace std;



void Menus::launchMenuFilters(const string& imagePath) {
    int choice;
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    do {
        cout << "CPMULTI\n";
        cout << "Please make your selection\n";
        cout << "1 - Use denoising filter\n";
        cout << "2 - Use invert colors filter\n";
        cout << "3 - Use median filter\n";
        cout << "4 - Use gaussian blur filter\n";
        cout << "5 - Use sobel filter\n";
        cout << "6 - Use canny filter\n";
        cout << "7 - Quit\n";
        cout << "Selection: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Filters::applyDenoising(image);
            // call denoising
                break;
            case 2:
                Filters::applyInvertColors(image);
            // call invert colors
                break;
            case 3:
                Filters::applyMedianFilter(image, 10); //Size
            // call median
                break;
            case 4:
                Filters::applyGaussianBlur(image);
            // call gaussian blur
                break;
            case 5:
                Filters::applySobel(image);
            // call sobel
                break;
            case 6:
                Filters::applyCannyEdgeDetection(image);
            // call canny;
                break;
            case 7:
                exit(0);
            default:
                exit(1);
        }
    } while (choice != 3);
    exit(0);
}


void Menus::launchMenuTransformation(const string& imagePath) {
    int choice;
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    do {
        cout << "CPMULTI\n";
        cout << "Please make your selection\n";
        cout << "1 - rotate image\n";
        cout << "2 - Quit\n";
        cout << "Selection: ";
        cin >> choice;

        switch(choice) {
            case 1:
                Transformations::rotateImageFromCenter(image, 20);

            break;
            case 2:
                exit(0);
            default:
                exit(1);
        }
    }
    while(choice !=3);
    exit(0);}



void Menus::launchMenu(const string& imagePath) {
    int choice;

    do {
        cout << "CPMULTI\n";
        cout << "Please make your selection\n";
        cout << "1 - Use filters\n";
        cout << "2 - Use transformations\n";
        cout << "3 - Quit\n";
        cout << "Selection: ";
        cin >> choice;

        switch(choice) {
            case 1:
                launchMenuFilters(imagePath);
            break;
            case 2:
                launchMenuTransformation(imagePath);
            break;
            case 3:
                exit(0);
            default:
                exit(1);
        }
    }
    while(choice !=3);
    exit(0);
}