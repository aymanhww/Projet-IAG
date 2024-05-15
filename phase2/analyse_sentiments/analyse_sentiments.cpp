#include "string"
#include "unordered_set"
#include "fstream"
#include "iostream"



class AnalysisResult {
public:
    // Constructeur
    AnalysisResult() : _positiveCount(0), _negativeCount(0) {}
    // Destructeur
    ~AnalysisResult() = default;
    void incPositiveCount() {
        _positiveCount++;
    }
    void incNegativeCount() {
        _negativeCount++;
    }
    void displaySentiment () const {
        std::cout << "Le résultat de l'analyse est " << _overallSentiment << std::endl;
    }
    void updateOverallSentiment(){
        /* Fonction appelée lorsque les compteurs positifs et négatifs ont été modifiés et qu'on veut mettre à jour
         * 'overallSentiment. */
        if (_positiveCount == _negativeCount){
            _overallSentiment = "Neutre";
        }
        else if (_positiveCount > _negativeCount){
            _overallSentiment = "Positif";
        }
        else if (_positiveCount < _negativeCount){
            _overallSentiment = "Négatif";
        }
    }
private:
    // Attributs
    std::string _overallSentiment;
    unsigned int _positiveCount;
    unsigned int _negativeCount;
};

class SentimentDictionary {
public:
    // Constructeur
    SentimentDictionary() : _positiveWords(), _negativeWords() {}
    // Destructeur
    ~SentimentDictionary() = default;
    // Getters
    std::unordered_set<std::string> getPositiveWords() const {
        return _positiveWords;
    }
    std::unordered_set<std::string> getNegativeWords() const {
        return _negativeWords;
    }
    // Setter
    void loadSentimentDictionary(const std::string& positivePath, const std::string& negativePath){
        bool positive = true;
        addWordsToDictionary(positivePath, positive);
        bool negative = false;
        addWordsToDictionary(negativePath, negative);
    }

    AnalysisResult analyzeSentiment(const std::string& filePath) {
        AnalysisResult currentAnalysis;
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
private:
    // Attribut
    std::unordered_set<std::string> _positiveWords;
    std::unordered_set<std::string> _negativeWords;
    // Méthode
    void addWordsToDictionary(const std::string& filePath, const bool& positive){
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
    };
};
