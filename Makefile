CFLAGS = -std=c++17 -O0 -g
LDFLAGS =

.PHONY: build clean run

build:
	clang++ $(CFLAGS) -o clrs main.cpp $(LDFLAGS)

clean:
	rm -rf clrs

run: clean build
	./clrs
