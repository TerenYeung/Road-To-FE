void GenerateIntegers(int *p, unsigned int n) {
  unsigned int i;
  Randomize();
  for(i=0; i<n; i++)
    *p++ = GenerateRandomNumber(lower_bound, upper_bound);
}

void ReverseIntegers(int *p, unsigned int n) {
  unsigned int i;
  for(i=0; i<n/2; i++)
    Swap(p+i, p+n-i-1);
}

void Swap(int *p, int *q) {
  int t;
  t = *p;
  *p = *q;
  *q = t;
}

void PrintIntegers(const int *p, unsigned int n) {
  unsigned int i;
  for(i=0; i<n; i++)
    count << setw(4) << *(p+i);
    cout << endl;a
}