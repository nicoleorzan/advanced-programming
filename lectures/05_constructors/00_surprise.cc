#include <iostream>

struct X {
  char member;
};

int main() {
  //the compiler generates on its own the things written in the right
  X x1;                 // default ctor. here I can create an object of type X without calling a constructor
  X x2{x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4{};               // default ctor calling {} to each member
  x4 = x3;              // copy assignment
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment
  std::cout << x5.member << std::endl;  // what do you expect??
  return 0;
}
//the members of the built-in type are not initialized by default
