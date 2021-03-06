#include <assert.h>
#include <cmath>
#include <iostream>

#include "ap_error.h"

// implment a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);

int main() {
  try {
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    double d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions
  // ap::sep=" --- ";
  if (d == 0)
    ap::error(
        "Do you really need to call a function to compute the square root of "
        "0???\n");
  if (d < 0)
    ap::error("Cannot handle negative numbers. I got", d);//I can put here after d as many parameters as I want
  if (d > 50)
    AP_error("The argument of square_root must be lower than 50. I got", d);
  //ap::internal::pretty_error(__FILE__,...);
  return sqrt(d);
}
