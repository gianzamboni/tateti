OBJS = main.o Tateti.o cositasDelSDL.o
CC = g++ -std=c++0x
DEBUG = -g
CFLAGS	 = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall -Werror -Wextra $(DEBUG) -std=c++0x
LIBRARIES = -lSDL2 

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main $(LIBRARIES)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBRARIES)

Tateti.o: Tateti/Tateti.cpp Tateti/Tateti.h
	$(CC) $(CFLAGS) Tateti/Tateti.cpp $(LIBRARIES)	

cositasDelSDL.o: cositasDelSDL.cpp cositasDelSDL.h
	$(CC) $(CFLAGS) cositasDelSDL.cpp $(LIBRARIES)	


clean:
	rm *.o
	rm main