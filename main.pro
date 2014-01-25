CONFIG -= qt
QMAKE_CFLAGS += -g 
QMAKE_CXXFLAGS += -g -I./HEADERS/

TARGET=PixelEscape

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SOURCES += $$PWD/SOURCES/*.cpp
HEADERS += $$PWD/HEADERS/*.hpp
