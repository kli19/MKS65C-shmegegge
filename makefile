all: shmegegge.o
	gcc shmegegge.o

shmegegge.o: shmegegge.c
	gcc -c shmegegge.c

clean:
	rm *.o
	rm a.out

run:
	./a.out
