
#include <iostream>

using namespace std;

int main() {
  int i, a[5], result = 0;
  for(i = 0; i < 5; i++) {
    cout << "Integer No." << i + 1 << ": ";
    cin >> a[i];
  }
  for(i = 0; i < 5; i++) {
    result += a[i];
  }
  cout << "The sum of elements of the array is " << result << endl;
  return 0;
}