CXX = g++
CXXFLAGS = -Wall

umbcracer: umbcracer.cpp Race.o Track.o Player.o
	$(CXX) $(CXXFLAGS) umbcracer.cpp Race.o Track.o Player.o -o umbcracer

Race.o: Race.h Race.cpp Track.o Player.o
	$(CXX) $(CXXFLAGS) -c Race.cpp

Track.o: Track.h Track.cpp
	$(CXX) $(CXXFLAGS) -c Track.cpp

Player.o: Player.h Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

clean:
	rm *~

run:
	./umbcracer
