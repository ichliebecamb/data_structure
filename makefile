VPATH=.

file=main.o \
	 seqlist.o \
	 list.o

exe:main
main:$(file)
	gcc -o main $(file)
$(file):

clean:
	rm *.o main
