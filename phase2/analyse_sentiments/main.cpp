#include <iostream>
#include "analyse_sentiments.hpp"

int main(){
    // Chargement du dictionnaire
    SentimentDictionary dictionnaire;
    dictionnaire.loadSentimentDictionary("positive.txt", "negative.txt");
    // Analyse des différents textes
    AnalysisResult positive = dictionnaire.analyzeSentiment("text_positif.txt");
    AnalysisResult negative = dictionnaire.analyzeSentiment("text_negatif.txt");
    AnalysisResult neutral = dictionnaire.analyzeSentiment("text_neutre.txt");
    // Résultats
    std::cout << "Résultats d'analyse :" << std::endl << std::endl;
    std::cout << "Fichier 1 ('text_positif') : "; positive.displaySentiment();
    std::cout << "Fichier 2 ('text_negatif') : "; negative.displaySentiment();
    std::cout << "Fichier 3 ('text_neutre') : "; neutral.displaySentiment();

    return 0;
}
