using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h>  

int main(){
  string line,unit;
  char uni[6], num[9];
  int k=0;
  
  getline(cin, line);
  unsigned int l = line.length();
  // cout<<"l: "<<l<<endl;
  
  for (int i=l-1;i>0;i--){
    if (line.at(i)>57) k++;
  }
  // cout<<"k: "<<k<<endl;
  size_t unimes =line.copy(uni,k,l-k); // numero totale e numero di partenza
  size_t number =line.copy(num,l-k,0); 
  //cout<<"parte in lettere: "<<uni<<endl;
  //cout<<"parte in cifre: "<<num<<endl;
  string unistring = uni;

  double numero =atoi(num);
  string convmes= "m";
  double convnum;

  if (unistring == "inch" || unistring == "inches"|| unistring == "pollice" || unistring == "pollici" ){
    convnum= numero*0.0254;
  }
  else if (unistring == "feet" || unistring == "foot"|| unistring == "piede" || unistring == "piedi" ){
    convnum= numero*0.3048;
  }
    else if (unistring == "mile" || unistring == "miles"|| unistring == "miglio" || unistring == "miglia" ){
    convnum= numero*1609.34;
  }

  cout<<"ho convertito in "<<convnum<<" "<<convmes<<endl;

  
  return 0;
}
