// Brainfuck interpreter
#include <iostream>
using namespace std;

// MAX MEMORY SIZE
#define MEM_SIZE 32768
#define SHIFTL '<'
#define SHIFTR '>'
#define INCREMENT '+'
#define DECREMENT '-'
#define OUT '.'
#define IN ','
#define JMPTO '['
#define JMPBF ']'

// program
char *p;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Invalid Argument" << endl;
    return 1;
  }
  p = argv[1];
  unsigned int ptr = 0;
  char memory[MEM_SIZE];
  memset(memory, 0, sizeof(memory));
  
  while (*p) {
    switch (*p) {
      // >
    case SHIFTR:
      ptr = (ptr >= MEM_SIZE-1) ? 0 : ptr+1;
      break;
      // <
    case SHIFTL:
      ptr = (ptr <= 0) ? MEM_SIZE-1 : ptr-1;
      break;
      // +
    case INCREMENT:
      memory[ptr]++;
      break;
      // -
    case DECREMENT:
      memory[ptr]--;
      break;
      // .
    case OUT:
      putchar(memory[ptr]);
      break;
      // ,
    case IN:
      memory[ptr] = getchar();
      break;
      // [
    case JMPTO:
      if (memory[ptr] == 0) {
        int nest = 0;
        for (;;) {
          p++;
          if (*p == JMPTO)
            nest++;
          if (*p == JMPBF)
            nest--;
          if (nest < 0)
            break;
        }
      }
      break;
      // ]
    case JMPBF:
      if (memory[ptr] != 0) {
        int nest = 0;
        for (;;) {
          p--;
          if (*p == JMPBF)
            nest++;
          if (*p == JMPTO)
            nest--;
          if (nest < 0)
            break;
        }
      }
      break;
      // それ以外は無視
    default:
      break;
    }
    p++;
  }
  cout << endl;
  return 0;
}
