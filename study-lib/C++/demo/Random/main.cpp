#include <iostream>
using namespace std;
#include "zyrandom.h"

int main()
{
  int i;
  Randomize();
  for (i=0; i<8; i++)
  {
    int t = GenerateRandomNumber(10, 99);
    cout << t << "; ";
  }
  cout << endl;
  for (i=0; i<8; i++)
  {
    double d = GenerateRandomReal(10.0, 99.0);
    cout << d << "; ";
  }
  return 0;
}