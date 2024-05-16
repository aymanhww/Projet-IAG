#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "cmath"
#include "unordered_map"


std::unordered_map<std::string, unsigned int> readDocument(const std::string& filePath){
    std::unordered_map<std::string, unsigned int> dicoMots;
    unsigned long int nombreMots = 0;
    std::ifstream file(filePath);
    if (file.is_open()){
        std::string mot;
        while (file >> mot){
            char last_letter = mot.back();
            if (last_letter == '.' or last_letter == ',' or last_letter == '?' or last_letter == ';' or last_letter == '!'){
                mot = mot.substr(0, mot.size() - 1);
            }
            mot[0] =  static_cast<char>(std::tolower(mot[0]));
            if (dicoMots.count(mot) == 0) {
                dicoMots[mot] = 1;
            }
            else {
                dicoMots[mot]++;
            }
            nombreMots++;
        }
        file.close();
        dicoMots["-1"] = nombreMots; // Valeur sentinelle pour stocker le nombre de mots
    }
    else {
        std::cout << "Erreur dans la lecture/ouverture du fichier." << std::endl;
    }
    return dicoMots;
}

std::unordered_map<std::string, double> computeTF(std::unordered_map<std::string, unsigned int>& words){
    std::unordered_map<std::string, double> termFrequencyMap;
    unsigned long int nombre_mots = words["-1"];
    for (const auto& paire : words){
        std::string mot = paire.first;
        unsigned long int frequency = paire.second;
        if (termFrequencyMap.count(mot) == 0){
            double tf = frequency / static_cast<double>(nombre_mots);
            termFrequencyMap[mot] = tf;
        }
    }
    return termFrequencyMap;
}

unsigned int countAppearances(const std::string& word, const std::vector<std::unordered_map<std::string, double>>& documents) {
    unsigned int appearances = 0;
    for (const auto &document : documents) {
        if (document.count(word) > 0) {
            appearances++;
        }
    }
    return appearances;
}

std::unordered_map<std::string, double> computeIDF(const std::vector<std::unordered_map<std::string, double>>& documentsTF, int totalDocuments){
    std::unordered_map<std::string, double> inverseDocumentFrequency;
    for (const auto& document : documentsTF){
        for (const auto& paire: document){
            std::string mot = paire.first;
            if (inverseDocumentFrequency.count(mot) != 0){
                unsigned int appearances = countAppearances(mot, documentsTF);
                double idf = log10(totalDocuments / static_cast<double>(appearances));
                inverseDocumentFrequency[mot] = idf;
            }
            }
        }
    return inverseDocumentFrequency;
}


std::unordered_map<std::string, double> calculateTFIDF(const std::unordered_map<std::string, double>& tf, const std::unordered_map<std::string, double>& idf){
    std::unordered_map<std::string, double> TFIDF = tf;
    std::unordered_map<std::string, double> idfCopy = idf;
    for (const auto& paire : TFIDF){
        std::string mot = paire.first;
        double tfScore = paire.second;
        TFIDF[mot] = tfScore * idfCopy[mot];
    }
    return TFIDF;
}

void displayTFIDFScores (const std::unordered_map<std::string, double>& tfidfScores){
    for (const auto & paire : tfidfScores){
        std::cout << paire.first << " >> " << paire.second << std::endl;
    }
}