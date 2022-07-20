#!/bin/bash

test() {
    input="$1"
    # brain fuck -> C lang をa.cに書き込み
    ./bf2c "$input" > a.c
    gcc -O2 -o a a.c
    time ./a
}

test  hello_world.bf
test  hello_world_17896.bf
test  fib.bf
test  sierpinski.bf
test  99beer.bf
test  mandelbrot.bf 
