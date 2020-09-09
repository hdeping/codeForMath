CC = gcc -g -lm
run:
	$(CC) main.c -o exe
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
