using namespace std;
#include <iostream>
#include <string>

int main(){
  int i=1;
  string line, line1;

  getline(cin,line);
  if (line.empty()) {
    cout<<"file vuoto"<<endl;
    return 1;
  }
    
    while(getline(cin,line1)){
      if (line==line1){
	i++;
	line=line1;
      }
      else{
	cout<<i<<" "<<line<<endl;
	i=1;
	line=line1;
      }
    }
  
  cout<<i<<" "<<line<<endl;
  
  return 0;
}
