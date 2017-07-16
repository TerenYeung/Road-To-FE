# include <iostream>

using namespace std;

int main()
{
  int n, i, sum = 0;
  cout << "The program gets a positive integer,\n";
  cout << "and prints the squared sum from 1 to the number.\n";
  cout << "The number: ";
  cin >> n;
  for(i = 1; i <= n; ++i)
    sum += i*i;
  cout << "The sum is " << sum << endl;
  return 0;
}