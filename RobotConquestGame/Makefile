output: main.o robot.o roomba.o bulldozer.o humanic.o optimusprime.o robocop.o
	      g++ -std=c++11 main.o robot.o roomba.o bulldozer.o humanic.o optimusprime.o robocop.o -o output
      
main.o: main.cpp
		g++ -c main.cpp

robot.o: robot.cpp robot.h
	  g++ -c robot.cpp

roomba.o: roomba.cpp roomba.h
	  g++ -c roomba.cpp
  
bulldozer.o: bulldozer.cpp bulldozer.h
	  g++ -c bulldozer.cpp
  
humanic.o: humanic.cpp humanic.h
	  g++ -c humanic.cpp
  
optimusprime.o: optimusprime.cpp optimusprime.h
	  g++ -c optimusprime.cpp

robocop.o: robocop.cpp robocop.h
	  g++ -c robocop.cpp
  
clean:
	rm *.o output


