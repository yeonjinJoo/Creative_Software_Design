all:main.o message.o
	g++ -o message_book main.o message.o

main.o:main.cpp
	g++ -c -o main.o main.cpp

message.o:message.cpp
	g++ -c -o message.o message.cpp

clean:
	rm main.o message.o


