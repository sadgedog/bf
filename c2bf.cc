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

  if (argc != 2) {
    cerr << "invalid argument" << endl;
    return 1;
  }
  // program
  p = argv[1];
  while (*p) {
    cout << p;
    p++;
  }
  cout << endl;
  return 0;
}
