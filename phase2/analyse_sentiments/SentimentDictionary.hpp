#include "string"
#include "unordered_set"
#include "ResultAnalysis.hpp"

class SentimentDictionary {
public:
    SentimentDictionary();
    ~SentimentDictionary();
    std::unordered_set<std::string> getPositiveWords() const;
    std::unordered_set<std::string> getNegativeWords() const;
    void loadSentimentDictionary(const std::string& positivePath, const std::string& negativePath);
    ResultAnalysis analyzeSentiment(const std::string& filePath);
private:
    std::unordered_set<std::string> _positiveWords;
    std::unordered_set<std::string> _negativeWords;
    void addWordsToDictionary(const std::string& filePath, const bool& positive);
};
