compile: fork.o fork.h
	gcc -o fork fork.o
run: fork
	./fork
fork.o: fork.c fork.h
	gcc -c fork.c
fork:
	make compile
