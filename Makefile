CFLAGS=-std=c++11

main:
	g++ $(CFLAGS) -o bfi bfi.cc
	g++ $(CFLAGS) -o bf2c bf2c.cc
	#g++ $(CFLAGS) -o c2bf c2bf.cc

bf2c:
	g++ $(CFLAGS) -o bf2c bf2c.cc

c2bf:
	g++ $(CFLAGS) -o c2bf c2bf.cc

a:
	gcc -O2 -o a a.c

test: main
	bash test.sh

test_bf2c: bf2c
	bash test_bf2c.sh

test_c2bf: c2bf
	./c2bf abc

clean:
	rm bfi bf2c a

.PHONY: test_bfi test_bf2c
