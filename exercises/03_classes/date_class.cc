#include <iostream>

//=====================================================================================
// START of Date class definitions
//=====================================================================================

enum class month_name { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
const unsigned int days_per_month[] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
  unsigned int _day;  //everything 1-based
  unsigned int _month;
  int _year;
  
public:
  Date (const unsigned int day, const unsigned int month, const int year) {
    _day = day;
    _month = month;
    _year = year;
    this->add_day(0); //rudimentary partial correction - it's there, why not using it?
  }
  
  Date (const unsigned int day, const month_name month, const int year) :
    Date(day, (unsigned int) int(month), year) {}  // delegating constructor - only available from C++11
  
  unsigned int day() const {return _day;}
  unsigned int month() const {return _month;}
  int year() const {return _year;}
  
  void add_day(const unsigned int n);
};

void Date::add_day(const unsigned int n) {
  _day += n;
  while (_day > days_per_month[_month - 1]) {
    _day -= days_per_month[_month - 1];
    _month += 1;
    if (_month > 12) {
      _month = 1;
      _year += 1;
    }
  }
}

bool operator==(const Date& lhs, const Date& rhs) {
  return (lhs.day()   == rhs.day()    &&
          lhs.month() == rhs.month()  &&
          lhs.year()  == rhs.year()   );
}

bool operator!=(const Date& lhs, const Date& rhs) {return !(lhs==rhs);}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  return os << date.day() << '/' << date.month() << '/' << date.year();  // d/m/y
}

bool is_leap(const int y) {
  return !(y % 4) && (y % 400);
}

//=====================================================================================
// END of Date class definitions
//=====================================================================================

using namespace std;

int main () {
  Date mydate(19, month_name::oct, 2017);
  cout << mydate << endl;
  mydate.add_day(366);
  cout << mydate << endl;
  Date mydate2(1, 11, 2017);
  cout << mydate2 << endl;

  cout << "2017 is";
  if (!is_leap(2017)) cout << "n't";
  cout << " a leap year" << endl;
  cout << "2016 is";
  if (!is_leap(2016)) cout << "n't";
  cout << " a leap year" << endl;
  cout << "2400 is";
  if (!is_leap(2400)) cout << "n't";
  cout << " a leap year" << endl;
  return 0;
}