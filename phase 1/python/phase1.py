import zipfile
import os


def decompress_archive(zip_path: str, extract_to: str):
    """
    Prend le chemin d'accès d'un fichier zip en parametre, et l'emplacement d'un repertoire de destination,
    verifie que le fichier zip donné en parametre en est bien un, decompresse les fichiers dans le repertoire de
    destination.
    """
    if not zipfile.is_zipfile(zip_path):
        raise zipfile.BadZipfile
    with zipfile.ZipFile(zip_path, 'r') as zip_file:
        zip_file.extractall(extract_to)


def organize_files(directory: str):
    """
    Prend le repertoire dans lequel organiser les fichiers en parametre, crée les sous dossiers necessaires s'ils
    n'existent pas deja, parcourt les fichiers du repertoire et deplace les fichiers dans les sous repertoires
    appropriés en fonctions de leurs extensions.
    """
    paths_names = ('Textes', 'Images', 'Audio', 'HTML', 'Videos')
    for name in paths_names:
        temp_path = directory + f'/{name}'
        if not os.path.exists(temp_path):
            os.makedirs(temp_path)

    for file in os.listdir(directory):
        file_to_redirect_path = directory + f'/{file}'
        if (os.path.splitext(file))[1] == '.txt':
            os.rename(file_to_redirect_path, directory + f'/Textes/{file}')
        elif (os.path.splitext(file))[1] in ('.jpg', '.png'):
            os.rename(file_to_redirect_path, directory + f'/Images/{file}')
        elif (os.path.splitext(file))[1] in ('.mp3', '.wav'):
            os.rename(file_to_redirect_path, directory + f'/Audio/{file}')
        elif (os.path.splitext(file))[1] == '.html':
            os.rename(file_to_redirect_path, directory + f'/HTML/{file}')
        elif (os.path.splitext(file))[1] in ('.mp4', '.avi'):
            os.rename(file_to_redirect_path, directory + f'/Videos/{file}')
