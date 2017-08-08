#include <iostream>
#include "Sales_item.h"
using namespace std;

// 1.20
// int main() {
//   for (Sales_item item; cin >> item; cout << item << endl);
//   return 0;
// }

// 1.21
// int main() {
//   Sales_item item1, item2;
//   cin >> item1 >> item2;
//   if (item1 == item2)
//     cout << item1 + item2 << endl;
//   else
//     cerr << "Different ISBN " << endl;
//     return -1;
//   return 0;
// }

// 1.22
// int main() {
//   Sales_item total;
//   if (cin >> total)
//   {
//     Sales_item trans;
//     while (cin >> trans)
//     {
//       if (trans.isbn() == total.isbn())
//         total += trans;
//       else
//       {
//         cout << total << endl;
//         total = trans;
//       }
//     }
//     cout << total << endl;
//   }
//   else
//   {
//     cerr << "No data" << endl;
//     return -1;
//   }
//   return 0;
// }

// 1.23
// 输入销售记录，并根据 ISBN 进行分类统计

int main()
{
  Sales_item curItem, valItem;
  if (cin >> curItem)
  {
    int count = 1;
    while (cin >> valItem)
    {
      if(curItem.isbn() == valItem.isbn())
      {
        ++count;
      }
      else
      {
        cout << curItem << " occurs " << count << " times " << endl;
        curItem = valItem;
        count = 1;
      }
    }
    cout << curItem << " occurs " << count << " times " << endl;
  }
  return 0;
}