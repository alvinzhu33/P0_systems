songs: main.c
	gcc main.c
	./a.out

list: mainL.c
	gcc mainL.c
	./a.out

clean:
	rm *~
	rm *.c#
