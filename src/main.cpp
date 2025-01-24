#include <opencv2/opencv.hpp>
#include <iostream>
#include "../include/ImageLoader.h"
#include "../include/Filters.h"
#include "../include/Transformations.h"
#include "../include/ImageSplitter.h"

int main() {
    std::string inputPath = "../data/input/photo.png";

    // Load image
    cv::Mat image = ImageLoader::loadImage(inputPath);
    if (image.empty()) {
        std::cerr << "Error on loading Image." << std::endl;
        return -1;
    }
    //ImageLoader::saveImage(image, "../data/output/result.png");

    // Afficher l'image originale
    cv::imshow("Image Originale", image);

    // 1. Appliquer un flou gaussien
    cv::Mat blur_image = Filters::applyGaussianBlur(image, cv::Size(5, 5),0);
    cv::imshow("Flou Gaussien", blur_image);

    // 2. Appliquer un filtre de détection de bords (Canny)
    cv::Mat edges = Filters::applyCannyEdgeDetection(image, 100, 200);
    cv::imshow("Detection des bords (Canny)", edges);

    // 3. Appliquer une inversion des couleurs
    cv::Mat inverted_image = Filters::applyInvertColors(image);
    cv::imshow("Inversion des couleurs", inverted_image);

    // 4. Appliquer une rotation de 45 degrés
    cv::Mat rotated_image = Transformations::rotateImageFromCenter(image, 45);
    cv::imshow("Rotation 45 degres", rotated_image);
   
    //cv::Mat sobel_image = Filters::applySobel(image);
    //cv::imshow("Sobel", sobel_image);

    //cv::Mat denoising_image = Filters::applyDenoising(image);
    //cv::imshow("Denoising", denoising_image);
    
  // 5. Diviser l'image en quatre parties
    std::vector<cv::Mat> subImages = ImageSplitter::splitImage(image);
    for (int i = 0; i < subImages.size(); i++) {
        cv::imshow("Sous-image " + std::to_string(i + 1), subImages[i]);
    }

    // Attendre que l'utilisateur appuie sur une touche pour fermer
    cv::waitKey(0);
  
   


    return 0;
}
