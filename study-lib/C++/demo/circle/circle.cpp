/* 圆类库的实现 */

#include "circle.h"

const double PI = 3.141592653;

Circle::Circle()
{
  r = 0.0, x = 0.0, y = 0.0;
}

Circle::Circle(double r, double x, double y)
{
  this->r = r, this->x = x, this->y = y;
}

void Circle::GetOrigin(double *x, double *y)
{
  *x = this->x;
  *y = this->y;
};

void Circle::SetOrigin(double x, double y)
{
  this->x = x;
  this->y = y;
};

double Circle::GetRadius()
{
  return r;
};

void Circle::SetRadius(double r)
{
  this->r = r;
};

double Circle::GetPerimeter()
{
  return 2*PI*r;
};

double Circle::GetArea()
{
  return PI*r*r;
};