CC = g++
CFLAGS = -Wall -I./HEADERS
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  $(CFLAGS)
SOURCES = $(wildcard SOURCES/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = game

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf SOURCES/*.o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.cpp
	$(CC) main.cpp $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@


