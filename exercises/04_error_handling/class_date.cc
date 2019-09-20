#include <iostream>
#include <string>
//already done in exercise 3-classes

using namespace std;

enum class Month{
  jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
    };
  struct Invalid_date {};

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

  unsigned int _d;
  unsigned int _y;
  Month _m;
  
  void add_singleday(){ _d+=1; }
  
public:
  
  Date(unsigned int day, Month month, unsigned int year){
    if(day<31 && int(month)<13){
      _d=day;
      _m=month;
      _y=year;
    } else {
      throw Invalid_date{};//cout<<"invalid date"<<endl};
    }
  }
  ~Date(){};
  
  unsigned int get_day() const {return _d;}
  Month get_month() const { return _m;}
  unsigned int get_year() const {return _y;}
  
  void add_days(const unsigned int n);

  bool is_leap(unsigned int _y){
    if (_y%4 == 0){
      if(_y%400!=0 ) return 1;
      else return 0;
    }
  }
  
  };

bool operator==(const Date& lhs, const Date& rhs){
  return ((lhs.get_day()==rhs.get_day()) && (lhs.get_month()==rhs.get_month()) && (lhs.get_year()==rhs.get_year()));
}

bool operator!=(const Date& lhs, const Date& rhs){
  return ((lhs.get_day()!=rhs.get_day()) && (lhs.get_month()!=rhs.get_month()) && (lhs.get_year()!=rhs.get_year()));
}

std::ostream& operator<<(std::ostream& os, const Date& d){
  return (os << d.get_day() <<", " << int(d.get_month()) << ", " <<d.get_year() );
}

std::istream& operator>>(std::istream& is, Month& mese){
    int a;
    is >> a;
    mese = static_cast<Month>(a);
    return is;
}


int main(){
  try{
  unsigned int day;
  unsigned int year;
  Month mese;// = Month::feb;
  cout<<"giorno? ";
  cin>>day;
  cout<<"mese? ";
  std::cin >> mese;
  cout<<"anno? ";
  cin>>year;
  Date data(day,mese,year);
  //int a = int(mese);
  
  cout<<"Data inserita:"<<endl;
  std::cout << data << '\n';

  unsigned int numero;
  cout<<"inserire giorni da aggiungere: ";
  cin>>numero;
  const unsigned int n = numero;
  cout<<"dopo "<<n<<" giorni sara` il ";
  data.add_days(n);
  std::cout << data << '\n';
    
  //int a2 = int(data.get_month());
  cout<<data.get_day();
  dwim(data.get_month());
  cout<<", anno "<<data.get_year()<<endl;
  
  return 0;
  } catch (const Invalid_date){
    std::cerr<<"Invalid date!\n";
    return 1;
  }
  
  }




void Date::add_days(const unsigned int n){
  int var=0;
  if (int(_m)==1 || int(_m)==3 || int(_m)==5 || int(_m)==7 || int(_m)==8 || int(_m)==10 || int(_m)==12) var=31;
  else if (int(_m)==4 || int(_m)==6 || int(_m)==9 || int(_m)==11 ) var=30;
  else if (int(_m)==2) var=29;
  for(int i=0;i<n;i++){
    if (_d<var) Date::add_singleday();
    else if (_d==var){
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
