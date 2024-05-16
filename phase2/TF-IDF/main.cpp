#include <vector>
#include <unordered_map>
#include <iostream>
#include "tf_idf.hpp"


int main(){
    std::unordered_map<std::string, unsigned int> vecteur1 = readDocument("medecine_1.txt");
    std::unordered_map<std::string, double> map1 = computeTF(vecteur1);
    std::unordered_map<std::string, unsigned int> vecteur2 = readDocument("medecine_2.txt");
    std::unordered_map<std::string, double> map2 = computeTF(vecteur2);
    std::unordered_map<std::string, unsigned int> vecteur3 = readDocument("medecine_3.txt");
    std::unordered_map<std::string, double> map3 = computeTF(vecteur3);

    std::vector<std::unordered_map<std::string, double>> documents = {map1, map2, map3};
    std::unordered_map<std::string, double> idf = computeIDF(documents, 3);

    std::unordered_map<std::string, double> tfidf1 = calculateTFIDF(map1, idf);
    std::unordered_map<std::string, double> tfidf2 = calculateTFIDF(map2, idf);
    std::unordered_map<std::string, double> tfidf3 = calculateTFIDF(map3, idf);

    std::cout << "TF-IDF Results :" << std::endl << std::endl;

    // medecine 1

    std::cout << "Fichier 1 ('medecine_1.txt) : " << std::endl << "---------------" << std::endl;
    displayTFIDFScores(tfidf1);
    std::cout << "---------------" << std::endl << std::endl;

    // medecine 2

    std::cout << "Fichier 2 ('medecine_2.txt) : " << std::endl << "---------------" << std::endl;
    displayTFIDFScores(tfidf2);
    std::cout << "---------------" << std::endl << std::endl;

    // medecine 3

    std::cout << "Fichier 3 ('medecine_3.txt) : " << std::endl << "---------------" << std::endl;
    displayTFIDFScores(tfidf3);
    std::cout << "---------------" << std::endl;

    return 0;
}