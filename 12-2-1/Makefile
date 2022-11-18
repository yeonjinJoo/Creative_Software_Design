all:calendar.o calendar_main.o
	g++ -o calendar calendar.o calendar_main.o

calendar.o:calendar.cc
	g++ -c -o calendar.o calendar.cc

calendar_main.o:calendar_main.cc
	g++ -c -o calendar_main.o calendar_main.cc

clean:
	rm calendar.o calendar_main.o


