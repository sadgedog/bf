# About this

brainfuck interpreter and bf to C translator\
80s(interpreter) -> 0.853s(C translated(optimized))

- Compile : make
- Run brainfuck interpreter Test : make test
- Run brainfuck to C lang translator Test : make test_bf2c

Comparison of execution speed

| Program name                | Brainfuck | C translated(Opt)|
|-----------------------------|-----------|--------|
| hello_world.bf (115 Bytes)  | 0.276s    | 0.105s |
| fib.bf (521 Bytes)          |  0.020s   | 0.214s |
| sierpinski.bf (1518 Bytes)  | 0.046s    | 0.248s |
| 99beer.bf (2676 Bytes)      | 0.690s    | 0.321s |
| mandelbrot.bf (11594 Bytes) | 82.096s   | 0.853s |