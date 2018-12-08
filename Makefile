SRC = main.cpp parser2.cpp
OBJ = $(SRC:.cpp =.o)

prog: $(OBJ)
	g++ $(OBJ) -o parser

.cpp.o: $<
	g++ -g -I. -c $<

clean:
	rm *.o parser
