all: FoldersAnalysis

FoldersAnalysis: FoldersAnalysis.o main.o
	g++ FoldersAnalysis.o main.o -o FoldersAnalysis -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2

FoldersAnalysis.o: FoldersAnalysis.cpp
	g++ -c FoldersAnalysis.cpp -o FoldersAnalysis.o -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2

main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2
