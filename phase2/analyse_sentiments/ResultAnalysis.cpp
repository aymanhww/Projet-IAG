#include "ResultAnalysis.hpp"
#include "string"
#include "iostream"


ResultAnalysis::ResultAnalysis() : _positiveCount(0), _negativeCount(0) {}

ResultAnalysis::~ResultAnalysis() = default;

void ResultAnalysis::incPositiveCount() {
    _positiveCount++;
}
void ResultAnalysis::incNegativeCount() {
    _negativeCount++;
}
void ResultAnalysis::displaySentiment () const {
    std::cout << "Le resultat de l'analyse est " << _overallSentiment << std::endl;
}
void ResultAnalysis::updateOverallSentiment(){
    /* Fonction appelée lorsque les compteurs positifs et négatifs ont été modifiés et qu'on veut mettre à jour
     * 'overallSentiment. */
    if (_positiveCount == _negativeCount){
        _overallSentiment = "Neutre";
    }
    else if (_positiveCount > _negativeCount){
        _overallSentiment = "Positif";
    }
    else if (_positiveCount < _negativeCount){
        _overallSentiment = "Negatif";
    }
}


