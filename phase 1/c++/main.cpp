#include "iostream"
#include "FoldersAnalysis.hpp"

int main(){
    FoldersAnalysis analyse;
    analyse.analyzeFolders("unzipped");
    analyse.displayResults();
    if (analyse.confidentialityProblem()) {
        std::cout << "Ce dossier contient des fichiers avec des problemes de confidentialite";
    }
    return 0;
}
