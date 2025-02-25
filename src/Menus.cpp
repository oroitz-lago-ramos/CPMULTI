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

void Menus::launchMenuChoiceThread(const cv::Mat &image, PerformanceAnalyzer& performance) {
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
                break;
            case 3:
                return;
            default:
                break;
        }
    } while (choice != 3);
}


void Menus::launchMenuFilters(const cv::Mat &image, bool useThread, PerformanceAnalyzer& performance) {
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
                    cv::Mat outputImage = ThreadPool::processImage(image, Filters::applyDenoising, performance);
                    imwrite("../data/output/output_denoise_thread.jpg", outputImage);
                } else {
                    performance.start("Denoising");
                    cv::Mat outputImage = Filters::applyDenoising(image);
                    performance.stop("Denoising");
                    imwrite("../data/output/output_denoise.jpg", outputImage);
                }
                break;
            case 2:
                if (useThread == true) {
                    cv::Mat outputImage = ThreadPool::processImage(image, Filters::applyInvertColors, performance);
                    imwrite("../data/output/output_invert_color_thread.jpg", outputImage);
                } else {
                    performance.start("Invert Colors");
                    cv::Mat outputImage = Filters::applyInvertColors(image);
                    performance.stop("Invert Colors");
                    imwrite("../data/output/output_invert_color.jpg", outputImage);
                    }
                break;
            case 3:
                if (useThread == true) {
                    cv::Mat outputImage = ThreadPool::processImage(image, Filters::applyMedianFilter, performance);
                    imwrite("../data/output/output_median_thread.jpg", outputImage);
                } else {
                    performance.start("Median Filter");
                    cv::Mat outputImage = Filters::applyMedianFilter(image);
                    performance.stop("Median Filter");
                    imwrite("../data/output/output_median.jpg", outputImage);
                }
                break;
            case 4:
                if (useThread == true) {
                    cv::Mat outputImage = ThreadPool::processImage(image, Filters::applyGaussianBlur, performance);
                    imwrite("../data/output/output_gaussian_thread.jpg", outputImage);
                } else {
                    performance.start("Gaussian Blur");
                    cv::Mat outputImage = Filters::applyGaussianBlur(image);
                    performance.stop("Gaussian Blur");
                    imwrite("../data/output/output_gaussian.jpg", outputImage);
                }
                break;
            case 5:
                if (useThread == true) {
                    cv::Mat outputImage = ThreadPool::processImage(image, Filters::applySobel, performance);
                    imwrite("../data/output/output_sobel_thread.jpg", outputImage);
                } else {
                    performance.start("Sobel");
                    cv::Mat outputImage = Filters::applySobel(image);
                    performance.stop("Sobel");
                    imwrite("../data/output/output_sobel.jpg", outputImage);
                }
                break;
            case 6:
                if (useThread == true) {
                    cv::Mat outputImage = ThreadPool::processImage(image, Filters::applyCannyEdgeDetection, performance);
                    imwrite("../data/output/output_canny_thread.jpg", outputImage);
                } else {
                    performance.start("Canny Edge Detection");
                    cv::Mat outputImage = Filters::applyCannyEdgeDetection(image);
                    performance.stop("Canny Edge Detection");
                    imwrite("../data/output/output_canny.jpg", outputImage);
                }
                break;
            case 7:
                return;
            default:
                break;
        }
    } while (choice != 3);
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
                    cv::Mat outputImage = ThreadPool::processImage(image, Transformations::rotateImageFromCenter,
                                                                  performance);
                   imwrite("../data/output/output_rotate_thread.jpg", outputImage);
                } else {
                    performance.start("Rotate Image");
                    cv::Mat outputImage = Transformations::rotateImageFromCenter(image);
                    performance.stop("Rotate Image");
                    imwrite("../data/output/output_rotate.jpg", outputImage);
                }

                break;
            case 2:
                return;
            default:
                break;
        }
    }
    while(choice !=3);
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
                return;
            default:
                break;
        }
    }
    while(choice !=3);
}