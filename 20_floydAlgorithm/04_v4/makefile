CC = gcc -g -o exe
run:
	$(CC) main.c 
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
g:
	gdb exe
p:
	gnuplot pic.sh
	gspng
	crop_png pic.png
	rm pic.png && mv newpic.png pic.png
	eog pic.png
