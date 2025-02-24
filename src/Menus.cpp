//
// Created by Lyes- on 08/02/2025.
//


#include "../include/Menus.h"
#include "../include/Filters.h"
#include "../include/Transformations.h"
#include "../include/ImageLoader.h"
#include "../include/ThreadPool.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Menus::launchMenuChoiceThread(const cv::Mat &image, PerformanceAnalyzer performance) {
    int choice;
    do {
        cout << "CPMULTI\n";
        cout << "Please make your selection\n";
        cout << "1 - Use Thread\n";
        cout << "2 - Don't use Thread\n";
        cout << "3 - Quit\n";
        cout << "Selection: ";
        cin >> choice;

        switch (choice) {
            case 1:
                launchMenu(image, true, performance);

                break;
            case 2:
                launchMenu(image, false, performance);

            case 3:
                exit(0);
            default:
                exit(1);
        }
    } while (choice != 3);
    exit(0);
}


void Menus::launchMenuFilters(const cv::Mat &image, bool useThread, PerformanceAnalyzer performance) {
    int choice;
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
                if (useThread == true) {
                    ThreadPool threadPool;
                    cv::Mat outputImage = threadPool.processImage(image, Filters::applyDenoising, performance);
                    cv::imwrite("../data/output/output.jpg", outputImage);
                } else { Filters::applyDenoising(image); }
            // call denoising
                break;
            case 2:
                if (useThread == true) {
                    ThreadPool threadPool;
                    cv::Mat outputImage = threadPool.processImage(image, Filters::applyInvertColors, performance);
                    cv::imwrite("../data/output/output.jpg", outputImage);
                } else { Filters::applyInvertColors(image); }
            // call invert colors
                break;
            case 3:
                if (useThread == true) {
                    ThreadPool threadPool;
                    cv::Mat outputImage = threadPool.processImage(image, Filters::applyMedianFilter, performance);
                    cv::imwrite("../data/output/output.jpg", outputImage);
                } else { Filters::applyMedianFilter(image); }
            // call median
                break;
            case 4:
                if (useThread == true) {
                    ThreadPool threadPool;
                    cv::Mat outputImage = threadPool.processImage(image, Filters::applyGaussianBlur, performance);
                    cv::imwrite("../data/output/output.jpg", outputImage);
                } else { Filters::applyGaussianBlur(image); }
            // call gaussian blur
                break;
            case 5:
                if (useThread == true) {
                    ThreadPool threadPool;
                    cv::Mat outputImage = threadPool.processImage(image, Filters::applySobel, performance);
                    cv::imwrite("../data/output/output.jpg", outputImage);
                } else { Filters::applySobel(image); }
            // call sobel
                break;
            case 6:
                if (useThread == true) {
                    ThreadPool threadPool;
                    cv::Mat outputImage = threadPool.processImage(image, Filters::applyCannyEdgeDetection, performance);
                    cv::imwrite("../data/output/output.jpg", outputImage);
                } else { Filters::applyCannyEdgeDetection(image); }
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

void Menus::launchMenuTransformation(const cv::Mat &image, bool useThread, PerformanceAnalyzer &performance) {
    int choice;
    do {
        cout << "CPMULTI\n";
        cout << "Please make your selection\n";
        cout << "1 - rotate image\n";
        cout << "2 - Quit\n";
        cout << "Selection: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (useThread == true) {
                    ThreadPool threadPool;
                    cv::Mat outputImage = threadPool.processImage(image, Transformations::rotateImageFromCenter,
                                                                  performance);
                    cv::imwrite("../data/output/output.jpg", outputImage);
                } else { Transformations::rotateImageFromCenter(image); }

                break;
            case 2:
                exit(0);
            default:
                exit(1);
        }
    }
    while(choice !=3);
    exit(0);
}

void Menus::launchMenu(const cv::Mat &image, bool useThread, PerformanceAnalyzer &performance) {
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
                launchMenuFilters(image, useThread, performance);
                break;
            case 2:
                launchMenuTransformation(image, useThread, performance);
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