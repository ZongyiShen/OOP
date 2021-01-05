# .PHONY: all
# CC = g++
# SRC = ./src
# BIN =./bin
# TEST = ./test
# CFLAGE = -Wfatal-errors
# LIB = -lgtest -lpthread

# all:src/dot.cpp test/ut_main.cpp mkdir
# 	g++ -std=c++11 -stdlib=libc++ test/ut_main.cpp src/vector.cpp src/circle.cpp -o bin/ut_all -Wfatal-errors -lgtest -lpthread
# 	#$(CC) $(TEST) $(SRC) $(CFLAG) $(LIB) -o$(BIN)/ut_all
# ut_all:test/ut_main.cpp mkdir

# mkdir:
# 	mkdir -p bin obj

# .PHONY:clean

# clean:
# 	rm -f bin/*
# 	rm -f obj/*

.PHONY: all
CC = g++ -std=c++11 -stdlib=libc++
SRC = ./src
BIN = ./bin
TEST = ./test
CFLAG = -Wfatal-errors
LIB = -lgtest -lpthread

#all: target
all: clean mkdir $(BIN)/ut_all

$(BIN)/ut_all : $(TEST)/ut_main.cpp $(SRC)/*.cpp
	$(CC) $(CFLAG) -o $@ $^ $(LIB)
	# $@ -> the name of target
	# $^ -> ALL dependenices of this target
	# $< -> the first dependenices of this target
mkdir:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
