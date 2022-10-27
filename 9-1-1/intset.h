#include <stdio.h>
#include <vector>

class IntegerSet {
  public:
    IntegerSet();
    ~IntegerSet(){};
    void AddNumber(int num);
    void DeleteNumber(int num);
    int GetItem(int pos);
    std::vector<int> GetAll();
    void PrintAll();

  private:
    std::vector<int> numbers_;
};