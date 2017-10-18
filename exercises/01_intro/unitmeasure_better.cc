using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h>  

int main(){
  int k=0;

  double numero;
  string uni;
  cin >> numero >> uni;

  string convmes="m";
  double convnum;
  const double inchconvert=0.0254;
  const double feetconvert=0.3048;
  const double mileconvert=1609.34;
  
  if (uni == "inch" || uni == "inches"|| uni == "pollice" || uni == "pollici" ){
    convnum= numero*inchconvert;
  }
  else if (uni == "feet" || uni == "foot"|| uni == "piede" || uni == "piedi" ){
    convnum= numero*feetconvert;
  }
    else if (uni == "mile" || uni == "miles"|| uni == "miglio" || uni == "miglia" ){
    convnum= numero*mileconvert;
  }

  cout<<"ho convertito in "<<convnum<<" "<<convmes<<endl;

  
  return 0;
}
