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
  cout << "char data[30000] = {};" << endl;
  cout << "char *ptr = data;" << endl;
  while (*p) {
    switch (*p) {
    case SHIFTL:
      cout << "--ptr;" << endl;
    case SHIFTR:
      cout << "++ptr;" << endl;
    case INCREMENT:
      cout << "++*ptr;" << endl;
    case DECREMENT:
      cout << "--*ptr;" << endl;
    case OUT:
      cout << "putchar(*ptr);" << endl;
    case IN:
      cout << "*ptr = getchar();" << endl;
    case JMPTO:
      cout << "while (*ptr) {" << endl;
    case JMPBF:
      cout << "}" << endl;
    default:
      cout << endl;
    }
    p++;
  }
  return 0;
}
