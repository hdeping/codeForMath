CC = gcc -O3
option = -o exe
source = 
object = sha256.o sha256_test.o
run:$(object)
	$(CC)  $(object) $(option)
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

