CFLAGS=-std=c++11
bf2c:
	g++ $(CFLAGS) -o bf2c bf2c.cc

test: bf2c
	bash test.sh

clean:
	rm bf2c

.PHONY: test
