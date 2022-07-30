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

  string indent = "";
  
  // prologue
  cout << "#include <stdio.h>" << endl;
  cout << endl;
  cout << "int main(void) {" << endl;
  cout << "  char data[30000] = {};" << endl;
  cout << "  char *ptr = data;" << endl;
  // code gen
  while (*p) {
    switch (*p) {
    case SHIFTL:
      cout << indent << "  --ptr;" << endl;
      break;
    case SHIFTR:
      cout << indent << "  ++ptr;" << endl;
      break;
    case INCREMENT:
      cout << indent << "  ++*ptr;" << endl;
      break;
    case DECREMENT:
      cout << indent << "  --*ptr;" << endl;
      break;
    case OUT:
      cout << indent << "  putchar(*ptr);" << endl;
      break;
    case IN:
      cout << indent << "  *ptr = getchar();" << endl;
      break;
    case JMPTO:
      cout << indent << "  while (*ptr) {" << endl;
      indent = "  ";
      break;
    case JMPBF:
      indent = "";
      cout << indent << "  }" << endl;
      break;
    default:
      cout << endl;
      break;
    }
    p++;
  }
  // epilogue
  cout << "  return 0;" << endl;
  cout << "}" << endl;
  return 0;
}
