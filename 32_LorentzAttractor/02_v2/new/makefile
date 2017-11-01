CXX = g++ -g
option = -o exe -lm -lGL -lGLU -lglut 
object += opengl.o
object += main.o
source = $(object:.o=.cpp)
run:$(object)
	$(CXX) $(object) $(option)
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
