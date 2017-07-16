# include <iostream>

using namespace std;

int main()
{
  int a, b, max;
  cout << "please inputs two value and prints the greater one.\n";
  cout << "the first value: ";
  cin >> a;
  cout << "the second value: ";
  cin >> b;
  max = a > b ? a : b;
  cout << "the greater one is: " << max << endl;
  return 0;
}