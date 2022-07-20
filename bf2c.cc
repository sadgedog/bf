// brainfuck to C lang
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
using namespace std;

constexpr char SHIFTL = '<';
constexpr char SHIFTR = '>';
constexpr char INCREMENT = '+';
constexpr char DECREMENT = '-';
constexpr char OUT = '.';
constexpr char IN = ',';
constexpr char JMPTO = '[';
constexpr char JMPBF = ']';

const char *p;

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "invalid argument" << endl;
    return 1;
  }
  // input file
  ifstream input_file(argv[1]);
  string str((istreambuf_iterator<char>(input_file)),
             istreambuf_iterator<char>());
  // program
  p = str.c_str();
  
  //p = argv[1];
  
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
