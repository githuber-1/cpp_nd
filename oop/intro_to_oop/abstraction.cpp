#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Date {
 public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);
  string String() const;

 private:
  bool LeapYear(int year) const;
  int DaysInMonth(int month, int year) const;
  int day_{1};
  int month_{1};
  int year_{0};
  unordered_map <int, string> const months_ = {{1, "January"},
                                        {2, "February"},
                                        {3, "March"},
                                        {4, "April"},
                                        {5, "May"},
                                        {6, "June"},
                                        {7, "July"},
                                        {8, "August"},
                                        {9, "September"},
                                        {10, "October"},
                                        {11, "November"},
                                        {12, "December"}
                                        };

};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

bool Date::LeapYear(int year) const {
  if (year % 4 != 0)
    return false;
  else if (year % 100 != 0)
    return true;
  else if (year % 400 != 0)
    return false;
  else
    return true;
}

int Date::DaysInMonth(int month, int year) const {
  if (month == 2)
    return LeapYear(year) ? 29 : 28;
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonth(Month(), Year())) day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12) month_ = month;
}

void Date::Year(int year) {
  year_ = year;
}

string Date::String() const {
    cout << " string" << endl;
    string s;
    string m;
    // getting around map access in const function, could use a vector instead
    auto it = months_.find(month_);

    if (it!= months_.end()) {
        m = it->second;
    }

    string d = to_string(day_);
    string y = to_string(year_);
    s += m + " ";
    s += d + ", ";
    s += y;

    cout << s << endl;
    return s;
}

// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.String() == "August 29, 1981");
}