#include <iostream>
#include <string>

using namespace std;

class Date{
  
  unsigned int _day, _month, _year;
  
public:

    Date(const unsigned int _day, const unsigned int _month, const unsigned int _year);
  ~Date();

  unsigned int day() const {return _day;}
  unsigned int month() const {return _month;}
  unsigned int year() const {return _year;}

  const int n;
  void add_day(const int n);

};


int main(){
  unsigned int day, month, year;
  cout<<"inserire data"<<endl;
  cin>>day>>month>>year;
  Date(day,month,year);
  int n;
  cout<<"giorni da aggiungere o togliere?"<<endl;
  cin>>n;
  add_day(n);
  return 0;
}

Date::Date(const unsigned int _day, const unsigned int _month, const unsigned int _year){
  if (_day>31 || _month>12){
    cout<<"invalid date"<<endl;
  }
}

Date::~Date(){
}

Date::add_day(const int n){

 
  if (_month==1 || _month==3 || _month==5 || _month==7 || _month==8 || _month==10){
    if (_day+n>31) {
      _month+=1;
      _day+=n-31;
    }
    else _day+=n;
  }
  else if (_month==4 || _month==6 || _month==9 || _month==11 ){
    if (_day+n>30) {
      _month+=1;
      _day+=n-30;
    }
    else _day+=n;
  }
  else if (_month==12){
    if (_day+n>30) {
      _month=1;
      _year+=1;
      _day+=n-30;
    }
    else _day+=n;
  }
  else if (_month==2){
    if (_year>1581 && _year%4==0){
      if (_day+n>29) {
	_month+=1;
	_day+=n-29;
      }
       else _day+=n;
    }
    else{
      if (_day+n>28){
	_month+=1;
	_day+=n-28;
      }
      else _day+=n;
    }
    }
  
}


