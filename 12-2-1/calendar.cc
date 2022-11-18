#include <iostream>
#include "calendar.h"
using namespace std;

MyCalendar::MyCalendar(){
  _year = 0;
  _month = 1;
  _day = 1;
}

bool MyCalendar::NextDay(int n){
  int y = _year;
  int m = 1;
  int d;
  int daysFromZero = ComputeDaysFromYearStart(_year,_month,_day);
  int changed = daysFromZero + n;
  if(changed < 0){
    while(!(changed >= 1 && changed <= GetDaysInYear(y))){
      y -= 1;
      if(y < 0){
        return false;
      }
      changed += GetDaysInYear(y);
    }
  }
  else if(changed > 0){
    while(!(changed >= 1 && changed <= GetDaysInYear(y))){
      changed -= GetDaysInYear(y);
      y += 1;
      if(y > 9999){
        return false;
      }
    }
  }
  else{
    y -= 1;
    if(y < 0){
      return false;
    }
    m = 12;
    d = 31;
  }
  while(changed != 0){
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
      if(changed > 31){
        changed -= 31;
        m += 1;
      }
      else{
        d = changed;
        break;
      }
    }
    else if(m!=2){
      if(changed > 30){
        changed -= 30;
        m += 1;
      }
      else{
        d = changed;
        break;
      }
    }
    else{
      if(GetDaysInYear(y) == 365){
        if(changed > 28){
          changed -= 28;
          m += 1;
        }
        else{
          d = changed;
          break;
        }
      }
      else{
        if(changed > 29){
          changed -= 29;
          m += 1;
        }
        else{
          d = changed;
          break;
        }
      }
    }
  }
  if(n != 0){
    _year = y;
    _month = m;
    _day = d;
  }
  return true;
}

bool MyCalendar::SetDate(int year, int month, int day){
  bool isyGood = (year >= 0 && year <=9999)? true:false;
  bool ismGood = (month >=1 && month <= 12)? true:false;
  if(!(isyGood&&ismGood)){
    return false;
  }
 if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
   if(!(day>=1 && day<=31)){
     return false;
   }
 }
 else if(month!=2){
   if(!(day>=1 && day<=30)){
     return false;
   }
 }
 else{
   if(GetDaysInYear(year) == 365){
     if(!(day>=1 && day<=28)){
       return false;
     }
   }
   else{
     if(!(day>=1 && day<=29)){
       return false;
     }
   }
 }
 _year = year;
 _month = month;
 _day = day;  
 return true;
}

int MyCalendar::year() const{
  return _year;
}

int MyCalendar::month() const{
  return _month;
}

int MyCalendar::day() const{
  return _day;
}

int MyCalendar::GetDaysInYear(int year){
  if(year%4 == 0){
    if(year%400!=0 && year%100==0){
      return 365;
    }
    else{
      return 366;
    }
  }
  else{
    return 365;
  }
}

int MyCalendar::ComputeDaysFromYearStart(int year, int month, int day){
  int days = 0;
  int daysInYear = GetDaysInYear(year);
  for(int i = 1; i <month; i++){
    if(i==1||i==3||i==5||i==7||i==8||i==10){
      days += 31;
    }
    else if(i!=2){
      days += 30;
    }
    else{
      if(daysInYear == 365){
        days += 28;
      }
      else{
        days += 29;
      }
    }
  }
  days += day;
  return days;
}

ostream& operator<<(std::ostream& out, const MyCalendar& c){
  out << c.year() << "." << c.month() << "." << c.day();
  return out;
}

istream& operator>>(std::istream& in, MyCalendar& c){
  char end;
  int y, m, d;
  in >> y >> end >> m >> end >> d;
  bool isGood = c.SetDate(y, m, d);
  if(!isGood){
    cout << "Invalid date: " <<y<<"."<<m<<"."<<d<<endl;
  }
  cout << c << endl;
  return in;
}