#include <iostream>

int get_int();
double get_double();

struct Getter_exception {
  std::string message;
};

int main() {
  int myint;
  double mydouble;
  try {
    std::cout << "Type four numbers in succession: two integers and two floats" << std::endl;
    myint = get_int();
    std::cout << "First integer: " << myint << std::endl;
    myint = get_int();
    std::cout << "Second integer: " << myint << std::endl;
    mydouble = get_double();
    std::cout << "First double: " << mydouble << std::endl;
    mydouble = get_double();
    std::cout << "Second double: " << mydouble << std::endl;
  } catch (const Getter_exception &exc) {
    std::cerr << exc.message << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception, aborting execution." << std::endl;
    return 2;
  }
  return 0;
}

int get_int() {
  int retval;
  if (!(std::cin >> retval)) {
    std::cin.clear();
    std::cin.ignore();
    throw Getter_exception{(std::string) "Error in " + __PRETTY_FUNCTION__ + ": invalid input"};
  }
  return retval;
}
  
double get_double() {
  double retval;
  if (!(std::cin >> retval)) {
    std::cin.clear();
    std::cin.ignore();
    throw Getter_exception{(std::string) "Error in " + __PRETTY_FUNCTION__ + ": invalid input"};
  }
  return retval;
}
