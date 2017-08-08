class Circle
{
  public:
    // 构造函数
    Circle();
    Circle(double r, double x = 0.0, double y = 0.0);
    ~Circle();
    void GetOrigin(double *x, double *y);
    void SetOrigin(double x, double y);
    double GetRadius(double r);
    void SetRadius(double r);
    double GetPerimeter();
    double GetArea();
  private:
    double r, x, y;
};