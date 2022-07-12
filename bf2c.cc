// brainfuck to C lang
#include <iostream>
using namespace std;

constexpr char SHIFTL = '<';
constexpr char SHIFTR = '>';
constexpr char INCREMENT = '+';
constexpr char DECREMENT = '-';
constexpr char OUT = '.';
constexpr char IN = ',';
constexpr char JMPTO = '[';
constexpr char JMPBF = ']';

char *p;

int main(int argc, char **argv) {

  p = argv[1];
  
  // initialize
  cout << "#include <stdio.h>" << endl;
  cout << "int main(void) {" << endl;
  cout << "char data[30000] = {};" << endl;
  cout << "char *ptr = data;" << endl;
  while (*p) {
    switch (*p) {
    case SHIFTL:
      cout << "--ptr;" << endl;
      break;
    case SHIFTR:
      cout << "++ptr;" << endl;
      break;
    case INCREMENT:
      cout << "++*ptr;" << endl;
      break;
    case DECREMENT:
      cout << "--*ptr;" << endl;
      break;
    case OUT:
      cout << "putchar(*ptr);" << endl;
      break;
    case IN:
      cout << "*ptr = getchar();" << endl;
      break;
    case JMPTO:
      cout << "while (*ptr) {" << endl;
      break;
    case JMPBF:
      cout << "}" << endl;
      break;
    default:
      cout << endl;
      break;
    }
    p++;
  }
  cout << "}" << endl;
  return 0;
}
