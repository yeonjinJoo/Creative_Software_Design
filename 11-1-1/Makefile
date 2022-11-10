all:my_string.o main.o
	g++ -o string my_string.o main.o

my_string.o:my_string.cpp
	g++ -c -o my_string.o my_string.cpp

main.o:main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm main.o my_string.o


