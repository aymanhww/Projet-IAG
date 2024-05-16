all: analyse_sentiments

analyse_sentiments: analyse_sentiments.o main.o
	g++ analyse_sentiments.o main.o -o analyse_sentiments -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2

analyse_sentiments.o: analyse_sentiments.cpp
	g++ -c analyse_sentiments.cpp -o analyse_sentiments.o -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2

main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2