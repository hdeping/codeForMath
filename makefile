com= gcc -O2 -g -o exe  -lm -L/usr/include
#all:run p
run:
	$(com) main.c
	./exe
p:
	gnuplot pic.sh
	evince pic.eps
