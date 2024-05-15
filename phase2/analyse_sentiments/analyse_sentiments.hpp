#include "string"
#include "unordered_set"

class AnalysisResult {
public:
    AnalysisResult();
    ~AnalysisResult();
    void incPositiveCount();
    void incNegativeCount();
    void displaySentiment() const;
    void updateOverallSentiment();
private:
    std::string _overallSentiment;
    unsigned int _positiveCount;
    unsigned int _negativeCount;
};

class SentimentDictionary {
public:
    SentimentDictionary();
    ~SentimentDictionary();
    std::unordered_set<std::string> getPositiveWords() const;
    std::unordered_set<std::string> getNegativeWords() const;
    void loadSentimentDictionary(const std::string& positivePath, const std::string& negativePath);
    AnalysisResult analyzeSentiment(const std::string& filePath);
private:
    std::unordered_set<std::string> _positiveWords;
    std::unordered_set<std::string> _negativeWords;
    void addWordsToDictionary(const std::string& filePath, const bool& positive);
};
