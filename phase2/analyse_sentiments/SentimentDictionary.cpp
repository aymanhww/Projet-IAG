#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "SentimentDictionary.hpp"


SentimentDictionary::SentimentDictionary() : _positiveWords(), _negativeWords() {}

SentimentDictionary::~SentimentDictionary() = default;

std::unordered_set<std::string> SentimentDictionary::getPositiveWords() const {
    return _positiveWords;
}
std::unordered_set<std::string> SentimentDictionary::getNegativeWords() const {
    return _negativeWords;
}

void SentimentDictionary::loadSentimentDictionary(const std::string& positivePath, const std::string& negativePath){
    bool positive = true;
    addWordsToDictionary(positivePath, positive);
    bool negative = false;
    addWordsToDictionary(negativePath, negative);
}

ResultAnalysis SentimentDictionary::analyzeSentiment(const std::string& filePath) {
    ResultAnalysis currentAnalysis;
    std::ifstream fileToAnalyze(filePath);
    if (fileToAnalyze.is_open()){
        std::string mot;
        while (fileToAnalyze >> mot){
            char lastLetter = mot.back();
            if (lastLetter == '.' or lastLetter == ',' or lastLetter == '?' or lastLetter == ';' or lastLetter == '!'){
                mot = mot.substr(0, mot.size() - 1);}
            mot[0] =  static_cast<char>(std::tolower(mot[0]));
            if (_positiveWords.find(mot) != _positiveWords.end()){
                currentAnalysis.incPositiveCount();
            }
            else if (_negativeWords.find(mot) != _negativeWords.end()){
                currentAnalysis.incNegativeCount();
            }
        }

    }
    else {
        std::cout << "Erreur lors de l'ouverture/lecture du fichier." << std::endl;
    }
    currentAnalysis.updateOverallSentiment();
    return currentAnalysis;
}

void SentimentDictionary::addWordsToDictionary(const std::string& filePath, const bool& positive){
    std::ifstream fileWords(filePath);
    if (fileWords.is_open()){
        std::string mot;
        while (fileWords >> mot){
            // Élimine les majuscules et ponctuations éventuelles.
            char lastLetter = mot.back();
            if (lastLetter == '.' or lastLetter == ',' or lastLetter == '?' or lastLetter == ';' or lastLetter == '!'){
                mot = mot.substr(0, mot.size() - 1);}
            mot[0] =  static_cast<char>(std::tolower(mot[0]));
            if (positive){
                _positiveWords.insert(mot);
            }
            else {
                _negativeWords.insert(mot);
            }
        }
        fileWords.close();
    }
    else {
        std::cout << "Erreur lors de l'ouverture/lecture du fichier." << std::endl;
    }
}
