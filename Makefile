OBJS = main.o Tateti.o 
CC = g++ -std=c++0x
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG) -std=c++0x
LIBRARIES = 

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main $(LIBRARIES)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBRARIES)

Tateti.o: tateti_struct/Tateti.cpp tateti_struct/Tateti.h
	$(CC) $(CFLAGS) tateti_struct/Tateti.cpp $(LIBRARIES)	
clean:
	rm *.o
	rm main