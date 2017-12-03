all: shell.c shell.h
	gcc -o CShell shell.c
	
run: all
	./CShell