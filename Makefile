CFLAGS = -g -Wall

main : main.o prompt.o operations.o matrix.o resol.o
	gcc $(CFLAGS) -o main main.o prompt.o operations.o matrix.o resol.o
	
main.o : main.c prompt.h
	gcc $(CFLAGS) -c main.c 
	
prompt.o : prompt.h prompt.c
	gcc $(CFLAGS) -c prompt.c

matrix.o : matrix.c matrix.h
	gcc $(CFLAGS) -c matrix.c
	
operations.o : operations.c operations.h matrix.h
	gcc $(CFLAGS) -c operation.c
	
resol.o : resol.c resol.h operations.h matrix.h
	gcc $(CFLAGS) -c resol.c
	
archive : 
	tar -f Oleemahomed_Thierry.tar.gz -cvz *.c *.h *.txt makefile
	
clean : 
	rm *.o

doc:
	doxygen Doxyfile
