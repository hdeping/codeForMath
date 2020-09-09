CC = gcc -g -o exe -lm
run:
	$(CC) main.c 
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
p:
	gnuplot pic.sh
	evince *eps
g:
	$(CC) main.c
	gdb exe
