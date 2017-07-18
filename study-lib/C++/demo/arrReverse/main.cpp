# include <iostream>
#include "arrmanip.h"
using namespace std;
# define NUMBER_OF_ELEMENTS 8
const int lower_bound = 10;
const int upper_bound = 99;

int main() {
  int a[NUMBER_OF_ELEMENTS];
  GenerateIntegers(a, NUMBER_OF_ELEMENTS,lower_bound,upper_bound);
  cout << "Array generated at random as follows: \n";
  PrintIntegers(a, NUMBER_OF_ELEMENTS);
  ReverseIntegers(a, NUMBER_OF_ELEMENTS);
  cout << "After all elements of the array reversed: \n";
  PrintIntegers(a, NUMBER_OF_ELEMENTS);
  return 0;
}