#include <iostream>
#include <stack>
using namespace std;

int main(void){
  stack<int> s;
  char type;
  string line;
  cin >> type;
  while(1){
    if(type == 'e'){
      bool isfalse = false;
      getline(cin, line);
      line = line.substr(1);
      for(int i = 0; i < line.size(); i++){
        if(line[i] == '('){
          s.push(1);
        }
        else if(line[i] == ')'){
          if(s.empty()){
            cout << "not matched" << endl;
            isfalse = true;
            break;
          }
          else{
            s.pop();
          }
        }
      }
      if(!(isfalse)){
        if(s.empty()){
          cout << "matched" << endl;
        }
        else{
          cout << "not matched" << endl;
          while(!(s.empty())){
            s.pop();
          }
        }
      }
    }
    else if(type == 'q'){
      break;
    }
    cin >> type;
  }
  return 0;
}