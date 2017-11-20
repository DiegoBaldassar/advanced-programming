#include <iostream>

int elab(int arg);

int main() {
  int retval = 0;
  std::cout << "Hello world!\n";
  return elab((float)retval);
}

int elab(int arg) {
  return arg;
}
