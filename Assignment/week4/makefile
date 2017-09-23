
files =	assignment1	assignment2     assignment3     assignment4     assignment5

assignment1:	fileopen.o
	gcc -o assignment1 fileopen.o

fileopen.o:	fileopen.c
	gcc -c fileopen.c

assignment2:	count.o
	gcc -o assignment2 count.o

count.o:	count.c
	gcc -c count.c

assignment3:	copyfile.o
	gcc -o assignment3 copyfile.o

copyfile.o:	copyfile.c
	gcc -c copyfile.c

assignment4:	fileopenend.o
	gcc -o assignment4 fileopenend.o

fileopenend.o:	fileopenend.c
	gcc -c fileopenend.c

assignment5:	io.o
	gcc -o assignment5 io.o

io.o:	io.c
	gcc -c io.c

all:	${files}
clean:	
	rm -f *.o ${files}
