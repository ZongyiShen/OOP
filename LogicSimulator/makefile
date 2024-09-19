.PHONY: all coverage
CC = g++ -std=c++11
SRC = ./src
BIN = ./bin
TEST = ./test
CFLAG = -Wfatal-errors -fprofile-arcs -ftest-coverage
LIB = -lgtest -lgmock -lpthread -lgcov

# all: target
all: clean mkdir $(BIN)/ut_all $(BIN)/main_program

# Compile the unit tests
$(BIN)/ut_all : $(TEST)/ut_main.cpp $(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))
	$(CC) $(CFLAG) -o $@ $^ $(LIB)

# Compile the main program
$(BIN)/main_program : $(SRC)/main.cpp $(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))
	$(CC) $(CFLAG) -o $@ $^

mkdir:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
	rm -f *.gcda *.gcno

# Coverage report target
coverage: $(BIN)/ut_all
	$(BIN)/ut_all
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info # Remove system files
	genhtml coverage.info --output-directory out


