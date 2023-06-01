CC = clang++
CFLAGS = -Wall -Wextra

.PHONY: run
run: a.out
	./a.out

a.out: main.cc
	$(CC) $(CFLGAS) main.cc

.PHONY: clean
clean:
	rm -f a.out
