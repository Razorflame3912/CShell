all: shell.o exec.o
	gcc -o CShell shell.o exec.o

shell.o: shell.c exec.h
	gcc -c shell.c
	
exec.o: exec.c exec.h
	gcc -c exec.c
	
run: all
	./CShell