all: tf_idf

tf_idf: tf_idf.o main.o
	g++ tf_idf.o main.o -o tf_idf -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2

tf_idf.o: tf_idf.cpp
	g++ -c tf_idf.cpp -o tf_idf.o -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2

main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2
