OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LIBRARIES = -lSDL

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main $(LIBRARIES)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBRARIES)

clean:
	rm *.o
	rm main