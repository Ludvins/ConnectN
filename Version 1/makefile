
CXX=g++
CXXFLAGS= -Wall -Wextra -pedantic -std=c++03 -g -Iincludes

#*****************Program generation*****************

all: bin/connectN

#******************Objects**********************

obj/Matrix.o : includes/Matrix.h src/Matrix.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/Matrix.o src/Matrix.cpp

obj/Board.o : includes/Matrix.h src/Matrix.cpp src/Board.cpp includes/Board.h
	$(CXX) -c $(CXXFLAGS) -o obj/Board.o src/Board.cpp

obj/BoardIO.o : includes/Player.h src/Board.cpp includes/Board.h includes/BoardIO.h src/BoardIO.cpp
		$(CXX) -c $(CXXFLAGS) -o obj/BoardIO.o src/BoardIO.cpp

obj/PlayerIO.o : includes/Player.h 
		$(CXX) -c $(CXXFLAGS) -o obj/PlayerIO.o src/PlayerIO.cpp

obj/Main.o :  src/Main.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/Main.o src/Main.cpp


#******************Exec file generation*************
bin/connectN: obj/Main.o obj/Board.o obj/BoardIO.o obj/Matrix.o obj/PlayerIO.o
	$(CXX) -o bin/ConnectN obj/Main.o obj/Board.o obj/BoardIO.o obj/Matrix.o obj/PlayerIO.o


#************************Cleaning******************
clean:
	echo "Cleaning..."
	rm obj/*.o

mrproper: clean
	rm bin/*
