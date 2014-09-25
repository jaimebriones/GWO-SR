all: exec

exec: GWO-C.o RngStream.o ConsFunctions.o StRnk.o
	gcc RngStream.o GWO-C.o ConsFunctions.o StRnk.o -o exec -lm -Wall

ConsFunctions.o: ConsFunctions.c ConsFunctions.h
	gcc -c ConsFunctions.c -lm

RngStream.o: RngStream.c RngStream.h 
	gcc -c RngStream.c -lm

GWO-C.o: GWO-C.c GWO-C.h
	gcc -c GWO-C.c -lm

StRnk.o: StRnk.c StRnk.h
	gcc -c StRnk.c -lm

clean:
	rm -rf *o exec