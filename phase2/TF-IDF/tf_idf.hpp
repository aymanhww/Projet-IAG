#include "string"
#include "vector"
#include "unordered_map"

std::unordered_map<std::string, unsigned int> readDocument(const std::string& filePath);
std::unordered_map<std::string, double> computeTF(std::unordered_map<std::string, unsigned int>& words);
std::unordered_map<std::string, double> computeIDF(const std::vector<std::unordered_map<std::string, double>>& documentsTF, int totalDocuments);
std::unordered_map<std::string, double> calculateTFIDF(const std::unordered_map<std::string, double>& tf, const std::unordered_map<std::string, double>& idf);
void displayTFIDFScores (const std::unordered_map<std::string, double>& tfidfScores);
unsigned int countAppearances(const std::string& word, const std::vector<std::unordered_map<std::string, double>>& documents);
