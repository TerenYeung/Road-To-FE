# include <iostream>

using namespace std;

// int main()
// {
//   int n, sum = 0;
//   cout << "The programe gets some integers, and outputs their sum.\n";
//   cout << "To stop, please input 0.\n";
//   cout << "Please input an interger:";
//   cin >> n;
//   while(n != 0)
//   {
//     sum += n;
//     cout << "The next integer:";
//     cin >> n;
//   }
//   cout << "The sum is: " << sum << "." << endl;
//   return 0;
// }

int main()
{
  int n, sum = 0;
  cout << "The programe gets some integers, and outputs their sum.\n";
  cout << "To stop, please input 0.\n";
  while(true)
  {
    cout << "Please input an integer:";
    cin >> n;
    if(n == 0)
      break;
    sum += n;
  }
  cout << "The sum is: " << sum << "." << endl;
  return 0;
}

