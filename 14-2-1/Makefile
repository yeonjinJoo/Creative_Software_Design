all:main.o calendar.o
	g++ -o calendar main.o calendar.o

main.o:main.cc
	g++ -c -o main.o main.cc

calendar.o:calendar.cc
	g++ -c -o calendar.o calendar.cc

clean:
	rm calendar.o main.o


