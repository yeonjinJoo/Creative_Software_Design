all:main.o setfunc.o
	g++ -o simple_int_set main.o setfunc.o

main.o:main.cpp
	g++ -c -o main.o main.cpp

setfunc.o:setfunc.cpp
	g++ -c -o setfunc.o setfunc.cpp

clean:
	rm main.o setfunc.o

