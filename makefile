CC = g++
CFLAGS = -c -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SOURCES = 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = game

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf *o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) src/main.cpp
	$(CC) src/main.cpp $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


