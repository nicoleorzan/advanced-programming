#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void gimme_int(const double d);

void gimme_real(const double d);

struct Real_Number{};

struct Int_Number{};

struct Char{};


void gimme_real(const double d){
  
  int i = d;
  if (i == d)
    throw Int_Number{};
  
  cout<<"yes this is a real"<<endl;

}


void gimme_int(const double d){

  int i = d;
  char c = d;
  if (i != d)
    throw Real_Number{};
  if (c == d)
    throw Char{};

  cout<<"yes this is an integer"<<endl;
}
 

int main() {
  try{
    double num;
    std::cout<<"write a integer number"<<std::endl;
    //std::cout<<"write a real number"<<std::endl;
    std::cin>>num;
    gimme_int(num);
    // gimme_real(num);
    return 0;
    /* } catch (const Int_Number) {
    std::cerr << "this is an integer! \n";
    return 1;*/
  } catch (const Real_Number) {
    std::cerr << "this is a double! \n";
    return 1;
  } catch (const Char) {
    std::cerr << "this is a char! \n";
    return 1;
  }catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 2;
  }
}
