#include <iostream>
#include "my_clock.h"

using namespace std;

void MyClock::Tick(int seconds){
  if(seconds > 0){
    _min += (_sec + seconds)/60;
    _sec = (_sec + seconds)%60;
    _hour += _min/60;
    _min = _min%60;
    _hour = _hour%24;
  }
  else{
    if((_sec + seconds) < 0){
      _min = _min - (-(_sec+seconds))/60-1;
      _sec = 60- (-(_sec+seconds))%60;
    }
    if(_min < 0){
      _hour = _hour - (-_min)/60 -1;
      _min = 60 -(-_min)%60;
    }
    if(_hour < 0 ){
      _hour = 24 - (-_hour)%24;
    }
  }
}

bool MyClock::SetTime(int hour, int minute, int second){
  bool ishGood = (hour <0 || hour > 23) ? false : true;
  bool ismGood = (minute <0 || minute > 59) ? false : true;
  bool issGood = (second <0 || second > 59) ? false : true;
  if(ishGood && ismGood && issGood){
    _hour = hour;
    _min = minute;
    _sec = second;
    return true;
  }
  else{
    return false;
  }
}

int MyClock::hour() const{
  return _hour;
}

int MyClock::minute() const{
  return _min;
}

int MyClock::second() const{
  return _sec;
}

ostream& operator<<(std::ostream& out, const MyClock& c){
  out << c.hour() << ":" << c.minute() << ":"<<c.second();
  return out;
}

istream& operator>>(std::istream& in, MyClock& c){
  char colon;
  int h, m, s;
  cin >> h >> colon >> m >> colon >> s;
  bool isGood = c.SetTime(h, m, s);
      if(!isGood){
        cout << "Invalid time: " << h <<":"<<m<<":"<<s<<endl;
      }
      cout << c << endl;
  return in;
}