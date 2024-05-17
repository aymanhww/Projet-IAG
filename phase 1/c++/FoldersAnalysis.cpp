#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "FoldersAnalysis.hpp"

FoldersAnalysis::FoldersAnalysis(): _txtFiles(0), _htmlFiles(0), _audioFiles(0), _imagesFiles(0), _videosFiles(0),
_confidentialityTxt(0), _confidentialityHtml(0), _wrongFileLocation(0) {}

std::string FoldersAnalysis::getLastDirectory(const std::filesystem::path& path_to_get){
    /* Prend un chemin d'accès en paramètre et retourne le nom du dernier dossier, utilisé lorsque qu'on veut savoir si
    un fichier se trouve bien dans son dossier attitré. */
    std::filesystem::path last_directory = path_to_get.filename();
    std::string str_to_return = last_directory.string();
    return str_to_return;}

bool FoldersAnalysis::wrongDirectory(const std::string& category, const std::string& extension){
    /* Prend une catégorie de fichier et une extension en paramètre, retourne false si l'extension ne correspond pas à
    la catégorie. */
    bool res = false;
    if (extension == ".mp3" or extension == ".wav"){
        res = (category != "Audio");
    }
    else if (extension == ".txt"){
        res = (category != "Textes");
    }
    else if (extension == ".html"){
        res = (category != "HTML");
    }
    else if (extension == ".jpg" or extension == ".png"){
        res = (category != "Images");
    }
    else if (extension == ".mp4"){
        res = (category == "Video");
    }
    return res;
}


bool FoldersAnalysis::checkFreeAccess(const std::filesystem::directory_entry& file){
    /* Prend un fichier en paramètre, retourne true s'il contient la mention "Licence : free access" au début. */
    bool res = false;
    std::string file_path = file.path().string();
    std::ifstream file_to_read(file_path);
    if (file_to_read.is_open()) {
        std::string line;
        std::string text = "Licence: free access";
        while (getline(file_to_read, line)) {
            if (line.find(text) != std::string::npos){
                res = true;
            }
        }
        file_to_read.close();
    }
    else {
        std::cout << "Erreur lors de l'ouverture du fichier.";
    }
    return res;
}

void FoldersAnalysis::analyzeFolders(const std::string &directory_path, bool display) {
    /* Parcourt les sous repertoires du repertoire donné en paramètre et identifie le nombre de fichiers par
    catégorie, vérifie pour les fichiers .html et .txt s'ils sont libres d'utilisation et identifie le nombre de
    fichiers dans la mauvaise catégorie. Affiche un rapport détaillé sur l'analyse. */
    for (const std::filesystem::directory_entry &subdirectory: std::filesystem::directory_iterator(
            directory_path)) {
        std::string files_category = getLastDirectory(subdirectory);
        for (const auto &file: std::filesystem::directory_iterator(subdirectory)) {
            std::string extension = std::filesystem::path(file).extension().string();
            if (wrongDirectory(files_category, extension)) {
                _wrongFileLocation++;
            }
            if (extension == ".mp3" or extension == ".wav") {
                _audioFiles++;
            } else if (extension == ".jpg" or extension == ".png") {
                _imagesFiles++;
            } else if (extension == ".mp4") {
                _videosFiles++;
            } else if (extension == ".html") {
                if (!checkFreeAccess(file)) {
                    _confidentialityHtml++;
                }
                _htmlFiles++;
            } else if (extension == ".txt") {
                if (!checkFreeAccess(file)) {
                    _confidentialityTxt++;
                }
                _txtFiles++;
            }
        }
    }
    if (display) {
        this->displayResults();
    }
}

bool FoldersAnalysis::confidentialityProblem() const {
    return (_confidentialityHtml + _confidentialityTxt) > 0;
}

void FoldersAnalysis::displayResults() const {
    /* Affiche les résultats de l'analyse */
    std::cout << "Resume par catégorie :"
    << std::endl << std::endl << "Textes :" << std::endl << " - Nombre de fichiers : "
    << _txtFiles << std::endl << " - Fichiers avec des problemes de confidentialite : " << _confidentialityTxt
    << std::endl << std::endl << "HTML :" << std::endl << " - Nombre de fichiers : "
    << _htmlFiles << std::endl << " - Fichiers avec des problemes de confidentialite : " << _confidentialityHtml
    << std::endl << std::endl << "Audio :" << std::endl << " - Nombre de fichiers : "
    << _audioFiles << std::endl << " - Fichiers avec des problemes de confidentialite : N/A"
    << std::endl << std::endl << "Images :" << std::endl << " - Nombre de fichiers : "
    << _imagesFiles << std::endl << " - Fichiers avec des problemes de confidentialite : N/A"
    << std::endl << std::endl << "Videos :" << std::endl << " - Nombre de fichiers : "
    << _videosFiles << std::endl << " - Fichiers avec des problemes de confidentialite : N/A"
    << std::endl << std::endl << "Diagnostic des eventuels problemes :" << std::endl << " - 'Licence free access' manquant dans "
    << _confidentialityTxt + _confidentialityHtml << " fichiers." << std::endl << " - " << _wrongFileLocation
    << " fichier(s) dans le mauvais dossier." << std::endl;
}