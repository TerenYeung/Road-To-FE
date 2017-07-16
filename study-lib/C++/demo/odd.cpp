# include <iostream>

using namespace std;

int main()
{
  int a, result;
  cout << "Please input a value.\nIf it is an even, output it directly,\n";
  cout << "otherwise multiply it by 3 then plus 1.\n";
  cout << "the value is: ";
  cin >> a;
  if (a%2 == 1)
    result = a * 3 + 1;
  else
    result = a / 2;
  cout << "the result is " << result << "." << endl;
  return 0;
}