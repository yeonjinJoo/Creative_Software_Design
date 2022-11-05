#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main(void){
  map<string, int> m, conclu;
  char type;
  string name;
  cin >> type;
  while(1){
    if(type == 'f'){
      cin >> name;
      ifstream file;
      file.open(name);
      string line;
      while(getline(file, line)){
        string copied = line;
        auto index = copied.find(" ");
        while(index != string::npos){
          string s = copied.substr(0, index);
          auto isExist = m.find(s);
          if(isExist == m.end()){
            m.insert({s, 1});
          }
          else{
            m[s] += 1;
          }
          copied = copied.substr(index+1);
          index = copied.find(" ");
        }
        if(m.find(copied) == m.end()){
          m.insert({copied, 1});
        }
        else{
          m[copied] += 1;
        }
      }
      int max = 1;
      int maxSize = 1;
      for(auto j = m.begin(); j != m.end(); j++){
        int compare = j -> second;
        if(compare > max){
          max = compare;
        }
      }
      for(auto j = m.begin(); j != m.end(); j++){
        int value = j -> second;
        string key = j -> first;
        if(value == max){
          conclu.insert({key, value});
          if(key.size() > maxSize){
            maxSize = key.size();
          }
        }
      }
      for(auto k = conclu.begin(); k!= conclu.end(); k++){
        string empty = " ";
        for(int q = 0; q < maxSize+1 - (k->first).size(); q++){
          empty += " ";
        }
        cout << k -> first << empty << k -> second << endl;
      }
      m.clear();
      conclu.clear();
    }
    else if(type == 'q'){
      break;
    }
    cin >> type;
  }
  return 0;
}