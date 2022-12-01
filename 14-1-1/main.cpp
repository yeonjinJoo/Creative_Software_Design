#include <iostream>
using namespace std;

class A{
  public:
    A(int n){
      if(n <= 0){
        throw "caught in the main";
      }
      cout << "ID=" << n << ": constructed\n";
      n_ID = n;
      data = new int[n];
    }
    ~A(){
      cout << "ID=" << n_ID << ": destroyed\n";
      delete data;
    }
  private:
    int* data = NULL;
    int n_ID;
};

int main(){
  try{
    A a(3);
    A b(2);
    {
      A c(1);
      A d(0); //여기서 exception throw 돼서 밑에 코드는 실행 안됨. 바로 catch로 달려가기
      A e(-1); //얜 아예 실행조차 안됨
    }
  }catch(const char* msg){
    cout << msg << endl;
  }
  return 0;
  //catch로 달려가는 과정에서 c 파괴. b 파괴. a 파괴.
}