all: LinkedList.o main.o
	g++ -o LinkedList LinkedList.o main.o

LinkedList.o: LinkedList.cc
	g++ -c -o LinkedList.o LinkedList.cc

main.o: main.cc
	g++ -c -o main.o main.cc

clean:
	rm LinkedList.o main.o
