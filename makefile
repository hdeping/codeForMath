CC = gcc -g -o exe -lm
object = main.o sort.o
source = main.c sort.c
run:$(object)
	$(CC) $(object)
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
p:
	gnuplot pic.sh
	evince *eps
clean:
	rm -fr $(object) exe
g:
	$(CC) $(source)
	gdb exe
all:clean  $(object)
	$(CC) $(object)
