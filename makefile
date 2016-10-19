songs: mainS.c
	gcc mainS.c
	./a.out

list: mainL.c
	gcc mainL.c
	./a.out

clean:
	rm *.c~
	rm *.h~
	rm *.c#
