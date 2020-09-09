CC = gcc -g -o exe
run:
	$(CC) main.c 
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
g:
	gdb exe
