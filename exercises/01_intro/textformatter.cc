using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>

#define TCPU_TIME (clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &ts ), (double)ts.tv_sec +  (double)ts.tv_nsec * 1e-9);



int main(){
  double tstart,ctime;
  struct timespec ts;
  tstart = TCPU_TIME;

  string line,line1, line2;
  char stringpart[25];
  int i,s=1,linemax=25;
  
  getline(cin,line);
  unsigned int l;

  while(line.length()>linemax){
    l = line.length();
    
    if (l>linemax){
      if (line.at(linemax) == ' ') {
	line1= line.substr(0,linemax);
	line2= line.substr(linemax+1,l);
	cout<<line1<<endl;
	line=line2;
	l = line.length();
      }
      else{
	i=linemax-1;
	while (line.at(i) != ' '){
	  i--;
	  s++;
	}
	line1= line.substr(0,i);
	line2= line.substr(i+1,l);
	cout<<line1<<endl;
	line=line2;
	l = line.length();
      }
    }
   
  }
  cout<<line<<endl;
  
  
  ctime += TCPU_TIME - tstart;
  cout<<"cpu time: "<<ctime<<endl;
  
  return 0;
}
