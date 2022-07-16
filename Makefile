CFLAGS=-std=c++11

main:
	g++ $(CFLAGS) -o bfi bfi.cc
	g++ $(CFLAGS) -o bf2c bf2c.cc

bf2c:
	g++ $(CFLAGS) -o bf2c bf2c.cc

a:
	gcc -O2 -o a a.c

test: main
	bash test.sh

test_bf2c: bf2c
	bash test_bf2c.sh

clean:
	rm bfi bf2c a

.PHONY: test_bfi test_bf2c
