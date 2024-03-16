
BUILD=../build

.PHONY: all

all:
	gcc -c -o ${BUILD}/heap.o -g heap.c
	gcc -c -o ${BUILD}/main.o -g main.c
	gcc -o ${BUILD}/main ${BUILD}/heap.o ${BUILD}/main.o
