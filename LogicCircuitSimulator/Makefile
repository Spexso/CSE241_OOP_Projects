output: main.o gate.o gate_and.o gate_or.o gate_decoder.o gate_not.o output.o input.o gate_flipflop.o
	      g++ -std=c++11 main.o gate.o gate_and.o gate_or.o gate_decoder.o gate_not.o output.o input.o gate_flipflop.o -o output
      
main.o: main.cpp
		g++ -c main.cpp

gate.o: gate.cpp gate.h
	  g++ -c gate.cpp

gate_and.o: gate_and.cpp gate_and.h
	  g++ -c gate_and.cpp
  
gate_or.o: gate_or.cpp gate_or.h
	  g++ -c gate_or.cpp
  
gate_decoder.o: gate_decoder.cpp gate_decoder.h
	  g++ -c gate_decoder.cpp
  
gate_not.o: gate_not.cpp gate_not.h
	  g++ -c gate_not.cpp

output.o: output.cpp output.h
	  g++ -c output.cpp
  
input.o: input.cpp input.h
	  g++ -c input.cpp
	  
gate_flipflop.o: gate_flipflop.cpp gate_flipflop.h
	  g++ -c gate_flipflop.cpp  
clean:
	rm *.o output


