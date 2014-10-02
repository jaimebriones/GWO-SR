all: exec

exec: GWO-C.o RngStream.o ConsFunctions.o StRnk.o
	gcc RngStream.o GWO-C.o ConsFunctions.o StRnk.o -O2  -o exec -lm -Wall

ConsFunctions.o: ConsFunctions.c ConsFunctions.h
	gcc -c ConsFunctions.c

RngStream.o: RngStream.c RngStream.h
	gcc -c RngStream.c

GWO-C.o: GWO-C.c GWO-C.h StRnk.h common.h
	gcc -c GWO-C.c

StRnk.o: StRnk.c StRnk.h RngStream.h ConsFunctions.h common.h
	gcc -c StRnk.c



clean:
	rm -rf *o exec
