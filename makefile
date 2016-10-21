songs: mainS.c
	gcc mainS.c
	./a.out

list: mainL.c
	gcc mainL.c
	./a.out

clean:
	rm *~
	rm *.c#
