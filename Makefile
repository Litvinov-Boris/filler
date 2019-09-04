NAME = test

$(NAME):
	gcc main.c
	gcc main2.c -o test
	./a.out| ./test