goal:	dijkstra.exe

GCC = g++

CCFLAGS = -fbounds-check -fstack-check -Wall -O2

OBJ = dijkstra.o

dijkstra.exe: $(OBJ)
	$(GCC) -o dijkstra.exe $(OBJ) $(CCFLAGS)

dijkstra.o: dijkstra.cpp
	$(GCC) -c dijkstra.cpp $(CCFLAGS)

clean:
	rm $(OBJ) dijkstra.o