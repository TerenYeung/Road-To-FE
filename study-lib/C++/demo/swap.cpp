# include <iostream>
using namespace std;
int a, b;
void Welcome();
int GetInteger(int idx);
// void Swap( int x, int y);
void Swap();

int main()
{
  // int a, b;
  Welcome();
  a = GetInteger(1);
  b = GetInteger(2);
  cout << "In main(): a:" << a << "; b:" << b << endl;
  Swap();
  cout << "In main(): a:" << a << "; b:" << b << endl;
  return 0;
}

void Welcome()
{
  cout << "The programe gets two integers, and tries to swap them.\n";
}

int GetInteger(int idx)
{
  int t;
  cout << "No." << idx << ":";
  cin >> t;
  return t;
}

// void Swap(int x, int y)
// {
//   int t;
//   cout << "In Swap(): x:" << x << "; y:" << y << endl;
//   t = x;
//   x = y;
//   y = t;
//   cout << "In Swap(): x:" << x << "; y:" << y << endl;
//   return;
// }
void Swap()
{
  int t;
  cout << "In Swap(): x:" << a << "; y:" << b << endl;
  t = a;
  a = b;
  b = t;
  cout << "In Swap(): x:" << a << "; y:" << b << endl;
  return;  
}
