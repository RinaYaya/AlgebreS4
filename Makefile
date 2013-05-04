CFLAGS = -g -Wall

main : main.o prompt.o
	gcc $(CFLAGS) -o main main.o prompt.o
	
main.o : main.c prompt.h
	gcc $(CFLAGS) -c main.c 
	
prompt.o : prompt.h prompt.c
	gcc $(CFLAGS) -c prompt.c

archive : 
	tar -f Oleemahomed_Thierry.tar.gz -cvz *.c *.h *.txt makefile
	
clean : 
	rm *.o

doc:
	doxygen Doxyfile
