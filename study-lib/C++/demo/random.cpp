# include <iostream>
# include <cstdlib>
# include <ctime>
# include "random.h"
using namespace std;
// int main()
// {
//   int i;
//   cout << "On this computer, the RAND_MAX is " << RAND_MAX << ".\n";
//   cout << "Five numbers the rand function generates as follows:\n";
//   // 这一步不是十分理解
//   srand((int)time(0));
//   for(i = 0; i < 5; i++)
//     cout << rand() << ";" << endl;
//   cout << "\n";
//   return 0;
// }
void Randomize()
{
  srand (int)time(NULL);
}

int GenerateRandomNumber(int low, int high)
{
  double _d;
  if(low > high)
  {
    cout << "GenerateRandomNumber: Make sure low <= high.\n";
    exit(1);
  }
  _d = (double)rand() / ((double)RAND_MAX + 1.0);
  return (low + (int)(_d*(hight - low + 1)));
}

double GenerateRandomReal(double low, double high)
{
  double _d;
  if(low > high)
  {
    cout << "GenerateRandomReal: Make Sure low <= high.\n";
    exit(2);
  }
  _d = (double)rand() / (double)RAND_MAX;
  return (low + _d * (high - low));
}