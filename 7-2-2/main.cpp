#include <iostream>
#include <string>
using namespace std;

int main(void){
  string sentence;
  getline(cin, sentence);
  if(sentence.find(',') == string::npos){
    cout << sentence << endl;
  }
  else{
    while(sentence.find(',') != string::npos){
      int a = sentence.find(',');
      cout << sentence.substr(0, a) << endl;
      sentence = sentence.substr(a+1);
    }
    if(sentence.length() != 0){
      cout << sentence << endl;
    }
  }
  return 0;
}