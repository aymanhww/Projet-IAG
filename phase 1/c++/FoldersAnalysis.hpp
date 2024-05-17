#include <string>
#include <filesystem>

class FoldersAnalysis {
public:
    FoldersAnalysis();
    ~FoldersAnalysis() = default;
    void analyzeFolders(const std::string &directory_path, bool display = false);
    void displayResults() const;
    bool confidentialityProblem() const;
private:
    // Attributs calculés a l'appel de analyzeFolders et utilisés a l'appel de displayResults.
    unsigned _txtFiles, _htmlFiles, _audioFiles, _imagesFiles, _videosFiles, _confidentialityTxt, _confidentialityHtml, _wrongFileLocation;
    // Fonctions utilisées lors des appels a analyzeFolders.
    static std::string getLastDirectory(const std::filesystem::path& path_to_get);
    static bool wrongDirectory(const std::string& category, const std::string& extension);
    static bool checkFreeAccess(const std::filesystem::directory_entry& file);
};