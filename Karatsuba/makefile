goal:	karatsuba.exe

GCC = g++

CCFLAGS = -fbounds-check -Wall -O2

OBJ = karatsuba.o

karatsuba.exe: $(OBJ)
	$(GCC) -o karatsuba.exe $(OBJ) $(CCFLAGS)

karatsuba.o: karatsuba.cpp
	$(GCC) -c karatsuba.cpp $(CCFLAGS)

clean:
	rm $(OBJ) karatsuba.o