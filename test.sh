#!bin/bash

echo "hello world"
time ./bfi hello_world.bf
echo "compliex hello world"
time ./bfi hello_world_17896.bf
echo "fibonacci"
time ./bfi fib.bf
echo "sierpinski"
time ./bfi sierpinski.bf
echo "99 bottle of beer"
time ./bfi 99beer.bf
echo "mandelbrot"
time ./bfi mandelbrot.bf 

echo OK
