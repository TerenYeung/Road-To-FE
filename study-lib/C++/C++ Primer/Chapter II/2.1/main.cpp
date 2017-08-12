#include <iostream>
#include <string>
using namespace std;

// int main()
// {
//   unsigned u = 10;
//   int i = -42;
//   cout << i + i << endl;
//   cout << u + i << endl;
//   return 0; 
// }

// 2.3
// int main()
// {
//   unsigned u = 10, u2 = 42;
//   cout << u2 - u << endl; // 32
//   cout << u - u2 << endl; // 4294967264
//   int i = 10, i2 = 42;
//   cout << i2 - i << endl; // 32
//   cout << i - i2 << endl; // -32
//   cout << i - u << endl; // 0
//   cout << u - i << endl; // 0
//   cout << "\145\n\012" << endl;
//   return 0;
// }

// 2.10
// string global_str; // ""
// int global_int; // 0
// int main()
// {
//   int local_int; // undefined
//   string local_str; // is uninitialized, but it has a value that is defined by the class
//   cout << global_str << endl;
//   cout << global_int << endl;
//   cout << local_int << endl;
//   cout << local_str << endl;
//   return 0;
// }

// 2.16
// int main()
// {
//   int i = 0, &r1 = i;
//   double d = 0, &r2 = d;
//   // r2 = 3.1415;
//   // cout << "d: " << d << endl;
//   // r2 = r1;
//   // cout << "d2: " << d << endl;
//   // i = r2;
//   // cout << "i: " << i << endl;
//   r1 = d;
//   cout << "i2: " << i << endl;
//   return 0;
// }

// 2.17
// int main()
// {
//   int i, &ri = i;
//   i = 5;
//   ri = 10;
//   cout << i << " " << ri << endl;
//   return 0;
// }

// 2.18
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