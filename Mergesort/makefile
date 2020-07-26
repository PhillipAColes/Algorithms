goal:	mergesort.exe

GCC = g++

CCFLAGS = -fbounds-check -fstack-check -Wall -O2

OBJ = mergesort.o

mergesort.exe: $(OBJ)
	$(GCC) -o mergesort.exe $(OBJ) $(CCFLAGS)

mergesort.o: mergesort.cpp
	$(GCC) -c mergesort.cpp $(CCFLAGS)

clean:
	rm $(OBJ) mergesort.o