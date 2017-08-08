#include <iostream>
using namespace std;
#include "circle.h"

int main()
{
  double r = 1.0, x = 0.0, y = 0.0;
  Circle circle(r, x, y);
  circle.SetOrigin(0.0, 0.0);
  circle.SetRadius(1.0);
  cout << "Perimeter:" << circle.GetPerimeter() << endl;
  cout << "Area:" << circle.GetArea() << endl;
  return 0;
}