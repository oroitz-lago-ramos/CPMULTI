//
// Created by Oroitz on 23/01/2025.
//

#include "../include/Transformations.h"

cv::Mat Transformations::rotateImageFromCenter(const cv::Mat &image) {
    cv::Mat result;
    cv::Point2f center(image.cols / 2, image.rows / 2);
    cv::Mat rotation_matrix = cv::getRotationMatrix2D(center, 52, 1.0);
    cv::warpAffine(image, result, rotation_matrix, image.size());
    return result;
}

cv::Mat Transformations::fourier(const cv::Mat& image) {
    // Convert to grayscale if the image is not already
    cv::Mat gray;
    if (image.channels() == 3) {
        cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    } else {
        gray = image.clone();
    }

    // Expand the image to an optimal size for DFT
    cv::Mat padded;
    int m = cv::getOptimalDFTSize(gray.rows);
    int n = cv::getOptimalDFTSize(gray.cols);
    cv::copyMakeBorder(gray, padded, 0, m - gray.rows, 0, n - gray.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    // Create planes for complex DFT
    padded.convertTo(padded, CV_32F); // Convertir en float
    cv::Mat planes[] = {padded, cv::Mat::zeros(padded.size(), CV_32F)};

    cv::Mat complexImage;
    cv::merge(planes, 2, complexImage);

    // Perform DFT
    cv::dft(complexImage, complexImage);

    // Split the real and imaginary parts
    cv::split(complexImage, planes);
    cv::magnitude(planes[0], planes[1], planes[0]); // Magnitude calculation
    cv::Mat magnitudeImage = planes[0];

    // Log scale transformation
    magnitudeImage += cv::Scalar::all(1);
    cv::log(magnitudeImage, magnitudeImage);

    // Crop and rearrange quadrants
    magnitudeImage = magnitudeImage(cv::Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
    int cx = magnitudeImage.cols / 2;
    int cy = magnitudeImage.rows / 2;

    cv::Mat q0(magnitudeImage, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(magnitudeImage, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(magnitudeImage, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(magnitudeImage, cv::Rect(cx, cy, cx, cy));

    cv::Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    // Normalize to displayable range
    cv::normalize(magnitudeImage, magnitudeImage, 0, 1, cv::NORM_MINMAX);

    return magnitudeImage;
}