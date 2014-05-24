CXX=clang++

INCLUDE=-Iinclude
CXXFLAGS=-Wall -std=c++11 $(INCLUDE)

EXEC=build/suprmarkt
TEST=$(EXEC)_test

SRC=$(shell find src -iname '*.cpp') main.cpp
SRC_TEST=$(shell find src tests -iname '*.cpp') main_test.cpp

all: compile

compile:
	@$(CXX) -o $(EXEC) $(SRC) $(CXXFLAGS)

test:
	@$(CXX) -o $(TEST) $(SRC_TEST) $(CXXFLAGS) -lgtest -pthread
	@./$(TEST)

clean:
	@$(RM) -rf build/*