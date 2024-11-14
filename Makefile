sae: sae.o test.o
	gcc -o sae *.o

sae.o: sae.c sae.h
	gcc -c sae.c

test.o: test.c
	gcc -c test.c

clean: 
	rm -f *.o sae