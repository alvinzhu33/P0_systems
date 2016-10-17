run: list.c
	gcc list.c
	./a.out

clean:
	rm *.c~
	rm *.h~
	rm *.c#
