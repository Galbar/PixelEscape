CC = g++
CFLAGS = -c -Wall -I./HEADERS -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
SOURCES = $(wildcard SOURCES/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = game

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.cpp
	$(CC) main.cpp $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


