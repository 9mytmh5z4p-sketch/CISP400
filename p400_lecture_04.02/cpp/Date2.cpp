Date2.cpp
#include<iostream>
using namespace std;
class Date {
   private:
    int mo;
    int day;
    int year;
   public:
    Date(int = 1, int = 1, int = 1);
    void PrintDate();
};
Date::Date(int m, int d, int y) {
   mo = m;
   day = d;
   year = y;
  if (mo > 12) mo = 99; // 99 is error SetDate
  // other checking goes here
}
void Date::PrintDate() {
   cout << mo << "/" << day << "/" << year << endl;
}

int main() {
   Date date1, date2(10,15,2009);
   Date date3(21,25,2017);
   cout << "Using default arguments: ";
   date1.PrintDate();
   cout << "Using passed arguments: ";
   date2.PrintDate();
   cout << "Error checking: ";
   date3.PrintDate();
}

/*
Date class w/ constructor as the interface. No setters and getters.
*/