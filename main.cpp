#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Charger l'image
    cv::Mat image = cv::imread("../image.png");
    
    // Vérifiez si l'image a été correctement chargée
    if (image.empty()) {
        std::cerr << "Erreur lors du chargement de l'image!" << std::endl;
        return -1;
    }

    // Afficher l'image originale
    cv::imshow("Image Originale", image);

    // 1. Appliquer un flou gaussien
    cv::Mat blur_image;
    cv::GaussianBlur(image, blur_image, cv::Size(5, 5), 0);
    cv::imshow("Flou Gaussien", blur_image);

    // 2. Appliquer un filtre de détection de bords (Canny)
    cv::Mat edges;
    cv::cvtColor(image, edges, cv::COLOR_BGR2GRAY);  // Convertir en niveaux de gris
    cv::Canny(edges, edges, 100, 200);  // Détection des bords
    cv::imshow("Detection des bords (Canny)", edges);

    // 3. Appliquer une inversion des couleurs
    cv::Mat inverted_image;
    cv::bitwise_not(image, inverted_image);
    cv::imshow("Inversion des couleurs", inverted_image);

    // 4. Appliquer une rotation de 45 degrés
    cv::Mat rotated_image;
    cv::Point2f center(image.cols / 2, image.rows / 2);
    cv::Mat rotation_matrix = cv::getRotationMatrix2D(center, 45, 1.0); // 45 degrés
    cv::warpAffine(image, rotated_image, rotation_matrix, image.size());
    cv::imshow("Rotation 45 degres", rotated_image);

    // Attendre que l'utilisateur appuie sur une touche pour fermer
    cv::waitKey(0);

    return 0;
}
