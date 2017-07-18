# include <iostream>
# include './Random/zyrandom.h'

using namespace std;

void GenerateIntegers(int a[], unsigned int n, int lower, int upper);

int main() {
  int i, a[5], n = 5, lower = 10, upper = 20;
  GenerateIntegers(a, n, lower, upper);
  for( i = 1; i < n; i++)
    cout << a[i] << endl;
  return 0;
}

void GenerateIntegers(int a[], unsigned int n, int lower, int upper) {
  unsigned int i;
  Randomize();
  for(i = 0;i < n;i++)
    a[i] = GenerateRandomNumber(lower, upper);
}