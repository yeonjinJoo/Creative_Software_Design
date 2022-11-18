#ifndef __CALENDAR_H__
#define __CALENDAR_H__

#include <iostream>

class MyCalendar{
public:
  MyCalendar();
  MyCalendar(int year, int month, int day);

  bool NextDay(int n = 1);
  bool SetDate(int year, int month, int day);

  int year() const;
  int month() const;
  int day() const;

private:
  static int GetDaysInYear(int year);
  //선언할때는 static
  static int ComputeDaysFromYearStart(int year, int month, int day);
// 이거 통해서 지금날짜 -> 오늘은 2022년의 309일째 날짜.. -100일 -> 209일 -> 년/월/일로 환산
  int _year, _month, _day; // 지금날짜
};

std::ostream& operator<<(std::ostream& out, const MyCalendar& c);
std::istream& operator>>(std::istream& in, MyCalendar& c);

#endif //__CALENDAR_H__