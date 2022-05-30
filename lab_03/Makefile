CXX = g++
CXXFLAGS = -g -Wall

all: UserInput/UserInput.o Person.o bin/Program clean

UserInput/UserInput.o: UserInput/UserInput.cpp UserInput/UserInput.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/Program: Person.o UserInput/UserInput.o MainProgram.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o UserInput/UserInput.o


