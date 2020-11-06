.PHONY: all
all:src/ConvString.cpp test/ut_main.cpp mkdir
	g++ -std=c++11 -stdlib=libc++ test/ut_main.cpp src/ConvString.cpp -o bin/ut_all -lgtest -lpthread

ut_all:test/ut_main.cpp mkdir

mkdir:
	mkdir -p bin obj

.PHONY:clean

clean:
	rm -f bin/*
	rm -f obj/*
