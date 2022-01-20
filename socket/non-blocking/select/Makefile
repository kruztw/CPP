CC  := g++
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%,$(SRC)) # convert all *.cpp to * , e.g. something.c to something

CFLAGS := -ggdb

all: $(OBJ)

.PHONY: clean
clean:
	-rm $(OBJ)


%: %.c
	-$(CC) $< -o $@ $(CFLAGS)
