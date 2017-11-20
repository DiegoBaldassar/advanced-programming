#include <iostream>

using namespace std;

int get_int();
double get_double();

int main() {
  int myint;
  double mydouble;
  cout << "Type four numbers in succession: two integers and two floats" << endl;
  myint = get_int();
  cout << "First integer: " << myint << endl;
  myint = get_int();
  cout << "Second integer: " << myint << endl;
  mydouble = get_double();
  cout << "First double: " << mydouble << endl;
  mydouble = get_double();
  cout << "Second double: " << mydouble << endl;
  return 0;
}

int get_int() {
  int retval;
  while (!(cin >> retval)) {
    cin.clear();
    cin.ignore();
  }
  return retval;
}
  
double get_double() {
  double retval;
  while (!(cin >> retval)) {
    cin.clear();
    cin.ignore();
  }
  return retval;
}
