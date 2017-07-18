# include <iostream>
# include <iomanip>
# include "../Random/zyrandom.h"
#include "arrmanip.h"

using namespace std;

void GenerateIntegers(int a[], unsigned int n, int lower, int upper) {
  unsigned int i;
  Randomize();
  for(i = 0; i < n; i++)
    a[i] = GenerateRandomNumber(lower, upper);
}

void ReverseIntegers(int a[], unsigned int n) {
  unsigned int i;
  for( i = 0; i < n/2; i++)
    SwapIntegers(a, i, n - i - 1);
}

void SwapIntegers(int a[], unsigned int i, unsigned int j) {
  int t;
  t = a[i], a[i] = a[j], a[j] = t;
}

void PrintIntegers(int a[], unsigned int n) {
  unsigned int i;
  for( i = 0; i < n; i++)
    cout << setw(3) << a[i];
  cout << endl;
}