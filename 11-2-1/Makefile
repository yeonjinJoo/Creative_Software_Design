all:my_vector.o main.o
	g++ -o MyVector my_vector.o main.o

my_vector.o:my_vector.cpp
	g++ -c -o my_vector.o my_vector.cpp

main.o:main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm my_vector.o main.o


