#ifndef __CALENDAR_H__
#define __CALENDAR_H__

#include <iostream>

class InvalidDate{
public:
  InvalidDate(int year, int month, int day);
  friend std::ostream& operator<<(std::ostream& out, const InvalidDate& msg);
  int year, month, day;
};

class MyCalendar{
public:
  MyCalendar();
  MyCalendar(int year, int month, int day);
  bool NextDay(int n = 1);

  //throw InvalidDate class
  void SetDate(int year, int month, int day);

  int year() const;
  int month() const;
  int day() const;

private:
  static int GetDaysInYear(int year);
  static int ComputeDaysFromYearStart(int year, int month, int day);

  int _year, _month, _day;
};

std::ostream& operator<<(std::ostream& out, const MyCalendar& c);
std::istream& operator>>(std::istream& in, MyCalendar& c);

#endif //__CALENDAR_H__