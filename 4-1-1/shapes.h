class Circle{
  private:
    int x_, y_, r_;

  public:
    void setInfo(int x, int y, int r);
    double Area();
    double Perimeter();
};

class Rectangle{
  private:
    int x_left_, y_left_, x_right_, y_right_;

  public: 
    void setInfo(int x_left, int y_left, int x_right, int y_right);
    double Area();
    double Perimeter();
};