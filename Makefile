CFLAGS = -g -Wall

main : main.o prompt.o operation.o matrix.o resol.o
	gcc $(CFLAGS) -o main main.o prompt.o operation.o matrix.o resol.o
	
main.o : main.c prompt.h
	gcc $(CFLAGS) -c main.c 
	
prompt.o : prompt.h prompt.c
	gcc $(CFLAGS) -c prompt.c

matrix.o : matrix.c matrix.h
	gcc $(CFLAGS) -c matrix.c
	
operation.o : operation.c operation.h matrix.h
	gcc $(CFLAGS) -c operation.c
	
resol.o : resol.c resol.h operation.h matrix.h
	gcc $(CFLAGS) -c resol.c
	
archive : 
	tar -f Oleemahomed_Thierry.tar.gz -cvz *.c *.h *.txt makefile
	
clean : 
	rm *.o

doc:
	doxygen Doxyfile
