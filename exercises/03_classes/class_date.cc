#include <iostream>
#include <string>

using namespace std;

enum class Month{
  jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
    };

void dwim(Month c) {
  switch (c) {
  case Month::jan:
    std::cout << ", mese gennaio";
    break;
  case Month::feb:
    std::cout << ", mese febbraio";
    break;
  case Month::mar:
    std::cout << ", mese marzo";
    break;
  case Month::apr:
    std::cout << ", mese aprile";
    break;
  case Month::may:
    std::cout << ", mese maggio";
    break;
  case Month::jun:
    std::cout << ", mese giugno";
    break;
  case Month::jul:
    std::cout << ", mese luglio";
    break;
  case Month::aug:
    std::cout << ", mese agosto";
    break;
  case Month::sep:
    std::cout << ", mese settembre";
    break;
  case Month::oct:
    std::cout << ", mese ottobre";
    break;
  case Month::nov:
    std::cout << ", mese novembre";
    break;
  case Month::dec:
    std::cout << ", mese dicembre";
    break;
  default:
    std::cout << ", invalid month!";
    break;
  }
}


class Date{

  unsigned int _d, _y;
  Month _m;
  
  void add_singleday(){ _d+=1; }
  
public:
  
  Date(unsigned int day, Month month, unsigned int year){
    if(day<31 && int(month)<12){ //sistemare
      _d=day;
      _m=month;
      _y=year;
    } else cout<<"invalid date"<<endl;
  }
  ~Date(){};//qui non ho capito perche` senza le graffe mi da errore
  
  const unsigned int get_day(){return _d;} //const davanti?
  const Month get_month(){ return _m;}
  const unsigned int get_year(){return _y;}
  
  void add_days(const unsigned int n);
  
  };

std::istream& operator>>(std::istream& is, Month& mese){
    int a;
    is >> a;
    mese = static_cast<Month>(a);
    return is;
}


int main(){

  unsigned int day, year;
  Month mese;// = Month::feb;
  cout<<"giorno? ";
  cin>>day;
  cout<<"mese? ";
  std::cin >> mese;
  cout<<"anno? ";
  cin>>year;

  //int a = int(mese);
  
  cout<<"Data: giorno "<<day;
  dwim(mese);
  cout<<", anno "<<year<<endl;
  Date data(day,mese,year);

  unsigned int numero;
  cout<<"inserire giorni da aggiungere: ";
  cin>>numero;
  const unsigned int n=numero;
  cout<<"dopo "<<n<<" giorni sara` il ";
  data.add_days(n);
  cout<<data.get_day();
  //int a2 = int(data.get_month());
  //cout<<", mese "<<a2;
  dwim(data.get_month());
  cout<<", anno "<<data.get_year()<<endl;;

    return 0;
  }




void Date::add_days(const unsigned int n){
    if (int(_m)==1 || int(_m)==3 || int(_m)==5 || int(_m)==7 || int(_m)==8 || int(_m)==10 || int(_m)==12){
      for(int i=0;i<n;i++){
	if (_d<31) Date::add_singleday();
	else if (_d==31){
	  _d=1;
	  if(int(_m)!=12){
	  int temp=int(_m)+1;
	  _m = (Month)temp;
	  }else{
	    _m = (Month)1;
	    _y+=1;
	  }
	}
      }
    }
    else if (int(_m)==4 || int(_m)==6 || int(_m)==9 || int(_m)==11 ){
      for(int i=0;i<n;i++){
	if (_d<31) Date::add_singleday();
	else if(_d==31){
	  _d=1;
	  int temp=int(_m)+1;
	  _m = (Month)temp;
	}
      }
    }
    else if (int(_m)==2){
      for(int i=0;i<n;i++){
	if (_d<29) Date::add_singleday();
	else if(_d==29){
	  _d=1;
	  int temp=int(_m)+1;
	  _m = (Month)temp;
	}
      }
    }
    
  }
