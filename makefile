CC = gcc -g -o exe -ligraph
object = main.o
source = main.c
run:$(object)
	$(CC) $(object)
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
g:
	$(CC) $(source)
	gdb exe
p:
	gnuplot pic.sh
	gspng
	crop_png pic.png
	rm pic.png
	eog newpic.png
clean:
	rm exe $(object)
d:
	sh dot.sh
