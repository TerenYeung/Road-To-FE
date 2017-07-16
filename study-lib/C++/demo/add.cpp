# include <iostream>

using namespace std;
int Add ( int x, int y );

int main()
{
  int a, b, sum;
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;
  sum = Add(a, b);
  cout << a << " + " << b << " = " << sum << endl;
  return 0;
}

int Add ( int x, int y )
{
  int t;
  t = x + y;
  return t;
}