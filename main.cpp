#include <iostream>
#include <fstream>

using namespace std;

// MAX MEMORY SIZE
#define MEM_SIZE 1024
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
  stack<int> s;
  memset(memory, 0, sizeof(memory));

  while (*p) {
    switch (*p) {
      // <
    case SHIFTL:
      ptr = (ptr <= 0) ? MEM_SIZE-1 : ptr-1;
      break;
      // >
    case SHIFTR:
      ptr = (ptr >= MEM_SIZE-1) ? 0 : ptr+1;
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
        while (*p != ']') {
          p++;
        }
      }
      break;
      // ]
    case JMPBF:
      if (memory[ptr] != 0) {
        while (*p != '[') {
          p--;
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
