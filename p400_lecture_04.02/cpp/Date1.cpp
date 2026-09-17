// Date1.cpp -- Simple date class
#include<iostream>
using namespace std;
class Date
{
   private:
      int mo;
      int day;
      int year;
   public:
      void SetDate(int = 1, int = 1, int = 2000);
      void PrintDate();
};
void Date::SetDate(int m, int d, int y)
{
   mo = m;
   day = d;
   year = y;
}
void Date::PrintDate()
{
   cout << mo << "/" << day << "/" << year << endl;
}

int main()
{
   Date date1, date2;
   date2.SetDate(10,15,2009);
   cout << "Using default arguments: ";
   date1.PrintDate();
   cout << "Using passed arguments: ";
   date2.PrintDate();
}

/*
Date class with setters and getters.
*/