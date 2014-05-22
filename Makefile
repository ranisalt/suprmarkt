CXX=clang++

INCLUDE=-Iinclude
CXXFLAGS=-Wall -std=c++11 $(INCLUDE)

EXEC=build/suprmarkt
TEST=$(EXEC)_test

SRC=$(shell find src -iname '*.cpp') main.cpp
TEST_SRC=$(shell find src tests -iname '*.cpp') main_test.cpp

all: test

build:
	@$(CXX) -o $(EXEC) $(SRC) $(CXXFLAGS)

test:
	@$(CXX) -o $(TEST) $(TEST_SRC) $(CXXFLAGS) -lgtest -pthread
	@./$(TEST)

clean:
	@$(RM) -rf build/*
