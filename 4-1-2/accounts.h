class Account{
  private:
   int ID_;
   int balance_ = 0;

  public:
   void setInfo(int ID);
   int getID();
   int getBalance();
   void setBalance(int balance);
};

class AccountManager{
  private:
   Account arr[10];
   int n = 0;

  public:
   void save(Account a);
   void increaseN();
   int getN();
   int deposit(int ID, int amount);
   int withdraw(int ID, int amount);
   int transfer(int ID1, int ID2, int amount);
   void check(int ID);
};
