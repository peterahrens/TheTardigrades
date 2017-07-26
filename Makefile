CC = pgcc
MPICC = mpicc
#CFLAGS = -std=c99 -pg 
CFLAGS = -acc -ta=tesla:cc60 -Minfo=accel -fast
OMPFLAGS = -fopenmp

all: mandelbrot.o main.o image.o run
clean:
	rm -rf run *.o *.dSYM

run: mandelbrot.o main.o image.o
	${CC} ${CFLAGS} -o run mandelbrot.o main.o image.o

mandelbrot.o: mandelbrot.c
	${CC} ${CFLAGS} -c mandelbrot.c

image.o: image.c
	${CC} ${CFLAGS} -c image.c

main.o: main.c
	${CC} ${CFLAGS} -c main.c

