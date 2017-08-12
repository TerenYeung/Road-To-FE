#include <iostream>
using namespace std;

int main()
{
  int i = 1, j = 2, *p = &i;
  cout << "p: " << *p << endl;
  p = &j;
  cout << "p: " << *p << endl;
  j = 3;
  cout << "p: " << *p << endl;
  return 0;
}