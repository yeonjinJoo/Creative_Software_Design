#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main(void){
  string sentence;
  while(1){
    getline(cin, sentence);
    if(sentence.compare("quit") == 0){
      break;
    }
    for(int i = 0; i < sentence.length(); i++){
      char a = sentence[i];
      if(islower(a)){
        sentence[i] = toupper(a);
      }
      else if(isupper(a)){
        sentence[i] = tolower(a);
      }
    }
    reverse(sentence.begin(), sentence.end());
    cout << sentence << endl;
  }
  return 0;
}