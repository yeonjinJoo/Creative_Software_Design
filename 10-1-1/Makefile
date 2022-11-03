all:main.o sorted.o
	g++ -o sorted_array main.o sorted.o

main.o:main.cpp
	g++ -c -o main.o main.cpp

sorted.o:sorted.cpp
	g++ -c -o sorted.o sorted.cpp

clean:
	rm main.o sorted.o


