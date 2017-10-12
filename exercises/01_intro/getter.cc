#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void realplease();
void intplease();

int main() {
  //intplease();
  realplease();
  return 0;
}

void realplease(){
  
  cout <<"dammi un reale"<<endl;
  double numdouble;
  cin>>numdouble;
  int numint = numdouble;
  while (numint == numdouble){
    cout<<"il numero è intero, dammi un reale"<<endl;
    cin>>numdouble;
    numint=numdouble;
  }
  cout<<"il numero è reale"<<endl;
  
}


void intplease(){

  cout <<"dammi un intero"<<endl;
  double numdouble;
  cin>>numdouble;
  int numint = numdouble;
  while (numint != numdouble){
    cout<<"il numero è reale, dammi un intero"<<endl;
    cin>>numdouble;
    numint=numdouble;
  }
  cout<<"il numero è intero"<<endl;
  
}
 

