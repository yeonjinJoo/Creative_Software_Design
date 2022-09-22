all: main.o shapes.o
	g++ -o simple_shape main.o shapes.o

main.o: main.cc
	g++ -c -o main.o main.cc

shapes.o: shapes.cc
	g++ -c -o shapes.o shapes.cc

clean:
	rm shapes.o main.o
