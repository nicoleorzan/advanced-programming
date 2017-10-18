#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(int argc, char* argv[]){
  if (argc != 2) {
    cerr << "Mi serve l'intervallo di numeri\n";
    return 7;
  }

  const int n = atoi(argv[1]);
  
  int* arr = new int[n-1];
  int num=2;
  for (int i = 0; i < n-1; i++) {
    arr[i]=num;
    num++;
    // cout<<arr[i]<<endl;
  }

    for (int i = 0; i < n-1; i++) {
      if (arr[i]!=0){
	for (int k = arr[i]; k < n-1; k++) {
	 if (arr[k]!=0){
	   if (arr[k]%arr[i]==0) arr[k]=0;
	 }
	}
      }
    }   

    cout<<"numeri primi da 2 a "<<n<<":"<<endl;
    for (int k = 0; k < n-1; k++) {
      if (arr[k]!=0) cout<< arr[k]<<endl;
    }
  
  delete[] arr;
  return 0;
}
