CFLAGS=-std=c++11
bfi:
	g++ $(CFLAGS) -o bfi bfi.cc

test: bfi
	bash test.sh

clean:
	rm bfi

.PHONY: test
