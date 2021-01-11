q1: main.o func.o
	g++ main.o func.o -o q1
main.o: main.cpp
	g++ main.cpp -c
func.o: func.cpp
	g++ func.cpp -c
clean:
	rm *.o q1
