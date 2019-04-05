CXX		  := g++ 
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb 

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= -lstdc++fs -lboost_system -lboost_filesystem
#LIB	:= stdc++fs

LIBRARIES	:= 
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): 
	$(CXX) $(SRC)/*.cpp $(CXX_FLAGS) $(LIB) -o $(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/*
