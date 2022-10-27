all: main.o intset.o
	g++ -o integer_set main.o intset.o

main.o:main.cpp
	g++ -c -o main.o main.cpp

intset.o:intset.cpp
	g++ -c -o intset.o intset.cpp

clean:
	rm main.o intset.o


