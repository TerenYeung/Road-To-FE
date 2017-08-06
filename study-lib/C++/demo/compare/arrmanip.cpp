#include <iostream>
using namespace std;

#include "random.h"
#include "arrmanip.h"

static const unsigned int lower_bound = 10;
static const unsigned int upper_bound = 99;

void GenerateIntegers(int a[], unsigned int n)
{
  unsigned int i;
  Randomize();
  for (i=0;i<n;i++)
    a[i] = GenerateRandomNumber(lower_bound, upper_bound)
}

int CompareInteger(int x, int y)
{
  if (x>y)
    return 1;
  else if(x==y)
    return 0;
  else
    return -1;
}

