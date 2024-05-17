#include "string"

class ResultAnalysis {
public:
    ResultAnalysis();
    ~ResultAnalysis();
    void incPositiveCount();
    void incNegativeCount();
    void displaySentiment() const;
    void updateOverallSentiment();
private:
    std::string _overallSentiment;
    unsigned int _positiveCount;
    unsigned int _negativeCount;
};
