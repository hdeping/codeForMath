com= gcc -O2 -g -o exe  -lm -L/usr/include
all:run p 
run:
	$(com) main.c
	./exe
p:
	gnuplot pic.sh
	evince pic.eps
p1:
	gnuplot pic_palette.sh
	gspng
	eog *png
p2:
	gnuplot pic_pm4d.sh
	evince out.eps
p3:
	gnuplot pic_pm4d_v2.sh
	evince out.eps
