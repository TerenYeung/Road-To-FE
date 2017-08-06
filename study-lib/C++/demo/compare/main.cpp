#include <iostream>
#include <cstdlib>
using namespace std;

#include "arrmanip.h"

#define NUMBER_OF_ELEMENTS 8

int DoCompareObject( const void *e1, const void *e2);

int main
{
  int a[NUMBER_OF_ELEMENTS];
  GenerateIntegers(a, NUMBER_OF_ELEMENTS)
  cout << "Array generated at random as follows: \n";
  PrintIntegers(a, NUMBER_OF_ELEMENTS);
  qsort(a, NUMBER_OF_ELEMENTS, sizeof(int), DoCompareObject);
  cout << "After sorted:\n";
  PrintIntegers(a, NUMBER_OF_ELEMENTS);
  return 0;
}

int DoCompareObject(const void 
*e1, const void *e2)
{
  return CompareInteger(*(const int *)el, *(const int *)e2);
}