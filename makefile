CC = gcc -g -lm -o exe
object = main.o triangle.o
run:$(object)
	$(CC) $(object)
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
