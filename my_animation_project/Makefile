CXX = g++
CXXFLAGS = -std=c++17 -I/usr/local/include -lftxui-screen -lftxui-dom -lftxui-component
LDFLAGS = -pthread

# Objetivos
all: run

run: bin/main

bin/main: src/main.cpp
    $(CXX) src/main.cpp -o bin/main $(CXXFLAGS) $(LDFLAGS)

clean:
    rm -f bin/main

