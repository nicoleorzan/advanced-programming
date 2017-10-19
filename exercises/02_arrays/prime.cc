#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//cerco i numeri primi da 2 a 100:  inizializzo un array vuoto di 50 elementi (so che tra 0 e 100 la meta` e` multiplo di 2 quindi li elimino), poi comincio un ciclo per cercare i numeri primi da 2 a 101. Per ognuno di questi, ad esempio un n fissato, se trovo un numero compreso tra 2 e sqrt(n) che diviso per n mi restituisce 0, allora la variabile booleana di controllo c assumera` il valore 1, altrimenti rimarra` 0. una volta finito il ciclo interno controllo il valore di c, se c==0 inserisco il numero nell'array dei numeri primi, altrimenti no. c viene quindi risettata a 0.

int main(){

  int prime[50]={0};
  bool c=0;
  int a=1;
  prime[0]=2;
  for(int i=3; i<101; i++){
    for(int k=2; k<=sqrt(i); k++){
      if (i%k==0) {
	c=1;
	break;
      }
    }
    if (c==0) {
      prime[a]=i;
      a++;
    }
    else if (c==1) c=0;
  }
  
  
  for(int i=0; i<50; i++){
    if (prime[i]!=0) cout<<prime[i]<<endl;
  }
  
  
  return 0;
}
