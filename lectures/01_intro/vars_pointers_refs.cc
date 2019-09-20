#include <iostream>

int main() {
  double d = 9.9;
  double &ref = d;
  double *ptr = &d;
  double a = d;
  std::cout << "content of   d: " << d << std::endl;
  std::cout << "content of   a: " << a << std::endl;
  std::cout << "content of ref: " << ref << std::endl;
  std::cout << "content of ptr: " << ptr << std::endl << std::endl;
  std::cout << "address of   d: " << &d << std::endl;
  std::cout << "address of   a: " << &a << std::endl;
  std::cout << "address of ref: " << &ref << std::endl;
  std::cout << "address of ptr: " << &ptr << std::endl;
  // std::cout << "&&d " << &(&d) << std::endl; doesn't work
}
