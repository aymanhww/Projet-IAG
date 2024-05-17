from phase1 import *


def main():
    decompress_archive("phase1_resources.zip", "unzipped")
    organize_files("unzipped")


if __name__ == "__main__":
    main()
