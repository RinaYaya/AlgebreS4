CFLAGS = -g -Wall
LIB = -lm
main : main.o prompt.o operations.o matrix.o resol.o speedtest.o
	gcc $(CFLAGS) -o main main.o prompt.o operations.o matrix.o resol.o speedtest.o  $(LIB)
	
main.o : main.c prompt.h
	gcc $(CFLAGS) -c main.c 
	
prompt.o : prompt.h prompt.c matrix.h operations.h resol.h
	gcc $(CFLAGS) -c prompt.c

matrix.o : matrix.c matrix.h
	gcc $(CFLAGS) -c matrix.c
	
operations.o : operations.c operations.h matrix.h
	gcc $(CFLAGS) -c operations.c
	
resol.o : resol.c resol.h operations.h matrix.h
	gcc $(CFLAGS) -c resol.c $(LIB)
	
speedtest.o: speedtest.c resol.h operations.h matrix.h
	gcc $(CFLAGS) -c speedtest.c $(LIB)
	
archive : 
	tar -f Oleemahomed_Thierry.tar.gz -cvz *.c *.h *.txt makefile
	
clean : 
	rm *.o

doc:
	doxygen Doxyfile
