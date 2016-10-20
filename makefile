songs: songs.c
	gcc songs.c
	./a.out

list: mainL.c
	gcc mainL.c
	./a.out

clean:
	rm *.c~
	rm *.h~
	rm *.c#
