#include <iostream>
#include <string>
using namespace std;


void return_pointer(int n);
template <typename num>
void print_reverse_vector(int n, const num* arr);

int main(){

  cout << "Please insert array lenght: ";
  int n;
  cin >> n;

  return_pointer(n);

  return 0;
}


void return_pointer(int n){
  double* arrd = new double[n];
  int* arri = new int[n];
  cout <<"Give me "<<n<<" double numbers"<<"\n";
  for (int i = 0; i < n; i++) cin>>arrd[i];

  cout <<"Give me "<<n<<" integer numbers"<<"\n";
  for (int i = 0; i < n; i++) cin>>arri[i];
  
  cout<<"primo elemento dell'array di interi: "<<arri[0]<< "\n";
  cout<<"il suo indirizzo in memoria è: "<<&arri[0]<<endl;
  cout<<"primo elemento dell'array di double: "<<arrd[0]<< "\n";
  cout<<"il suo indirizzo in memoria è: "<<&arrd[0]<<endl;
  print_reverse_vector<double>(n,arrd);
  print_reverse_vector<int>(n,arri);
  
  delete[] arrd;
  delete[] arri;
}

template <typename num>
void print_reverse_vector(int n, const num* arr){// int arr[]= int* arr, e arr=&arr[0];
  cout <<"elementi dell'array in ordine inverso:"<<"\n";
  for (int i=n-1; i>=0; i--)
    cout<<i<<": "<<arr[i]<<"\n";
}


