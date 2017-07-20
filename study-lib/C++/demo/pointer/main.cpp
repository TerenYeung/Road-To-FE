#include <iostream>

using namespace std;

// int main() {
//   int n = 10;
//   int *p = &n;
//   cout << "address: " << p << endl;
//   cout << "value: " << *p << endl;
//   return 0;
// }

// int main() {
//   int m = 10, n = 20, t;
//   int *p = &m, *q = &n;
//   cout << "m: " << m << "; n: " << n << endl;
//   t = *p;
//   *p = *q;
//   *q = t;
//   cout << "m: " << m << "; n: " << n << endl;
//   return 0;
// }

// void Swap(int *x, int *y);
// int main() {
//   int m = 10, n = 20;
//   #ifndef NDEBUG
//     cout << "main (before swapped): m = " << m << "; n = " << n << endl;
//   #endif
//   Swap( &m, &n);
//   #ifndef NDEBUG
//     cout << "main (after swapped): m = " << m << "; n = " << n << endl;
//   #endif
//   return 0;
// }

// void Swap(int *x, int *y) {
//   int t;
//   if (!x || !y) {
//     cout << "Swap: Parameter(s) illegal." << endl;
//     exit(1);
//   }
//   #ifndef NDEBUG
//     cout << "Swap (before swapped): *x = " << *x << "; *y = " << *y << endl;
//   #endif
//   t = *x;
//   *x = *y;
//   *y = t;
//   #ifndef NDEBUG
//     cout << "Swap (after swapped): *x = " << *x << "; *y = " << *y << endl;
//   #endif
// }

