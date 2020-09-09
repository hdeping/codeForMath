object=main.o day.o
run:$(object)
	gcc -g -o exe $(object)
	./exe
