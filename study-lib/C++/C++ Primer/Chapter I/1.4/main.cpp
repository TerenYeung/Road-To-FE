#include <iostream>
// 1.9
// int main()
// {
//   int sum = 0, i = 50;
//   while (i<=100) {
//     sum += i;
//     ++i;
//   }
//   std::cout << "The sum of 50 and 100 is "
//             << sum;
//   return 0;
// }

// int main()
// {
//   int i = 10;
//   while( i>=0 )
//   {
//     std::cout << "the current number is " << i << std::endl;
//     --i;
//   }
//   return 0;
// }

// int main()
// {
//   int x, y, tmp;
//   std::cout << "please input two numbers: " << std::endl;
//   std::cin >> x >> y;
//   if (x > y) {
//     tmp = x;
//     x = y;
//     y = x;
//   }
//   while(x<=y)
//   {
//     std::cout << x << std::endl;
//     ++x;
//   }
//   return 0;
// }

// 1.13
// int main()
// {
//   int sum = 0;
//   for (int i = -100; i<=100; i++)
//     sum += i;

//   std::cout << sum << std::endl;
//   return 0;
// }

// 读取输入数量不定的数据

// int main()
// {
//   int sum = 0, value = 0;
//   while (std::cin >> value)
//     sum += value;
//   std::cout << "Sum is " << sum << std::endl;
//   return 0;
// }

// 1.15
// int main(
// {
//   std::cout << "Read each file." << std::endl:
//   std::cout << Update master. << std::endl;
//   std::cout << "Write new master." std::endl;
//   return 0
// }

// 1.16
// int main()
// {
//   int value = 0, sum = 0;
//   std::cout << "pls input a serial of numbers :" << std::endl;
//   while (std::cin >> value)
//     sum += value;
//   std::cot << sum << std::endl;
//   return 0;
// }

int main()
{
  int curValue, val;
  if (std::cin >> curValue)
  {
    int count = 1;
    while (std::cin >> val)
    {
      if ( val == curValue )
        ++count;
      else
      {
        std::cout << curValue << " occurs "
                  << count << " times " << std::endl;
        curValue = val;
        count = 1;
      }
    }
    std::cout << curValue << " occurs "
              << count << " times " << std::endl;
  }
  return 0;
}