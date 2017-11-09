joker: joker.c
	gcc joker.c
run: a.out
	./a.out
clean: a.out
	rm a.out
	rm joker.log
