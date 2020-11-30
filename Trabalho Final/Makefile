clean: main
	rm *.o 
main: main.o simulation.o fileandplot.o calc.o
	gcc -o main  main.o simulation.o fileandplot.o calc.o -lm
main.o: main.c
	gcc -c main.c -lm

simulation.o: simulation.c simulation.h
	gcc -c simulation.c -lm

fileandplot.o: fileandplot.c fileandplot.h
	gcc -c fileandplot.c -lm

calc.o: calc.c calc.h
	gcc -c calc.c -lm
