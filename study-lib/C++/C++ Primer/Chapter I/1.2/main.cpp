// C++ 的标准输入输出
// 定义在 iostream 库中，该库包含两个基础类型 istream 和 ostream；
// cin 是 istream 类型的对象
// cout 是 ostream 类型的对象

#include <iostream> // 引入 iostream 头文件，告诉编译器想要使用 iostream 库

// int main()
// {
//   std::cout << "Enter two numbers:" << std::endl;
//   int x = 0, y = 0;
//   std::cin >> x >> y;
//   std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
//   return 0;
// }

// << 输出运算符接受两个运算对象，左侧运算对象必须是一个 ostream 对象，右侧是打印的值，输出运算符的计算结果就是其左侧运算对象
// >> 输入运算符原理同上

// 1.3
// int main()
// {
//   std::cout << "Hello World." << std::endl;
// }

// 1.4
// int main()
// {
//   int x = 0, y = 0;
//   std::cout << "Enter two numbers:" << std::endl;
//   std::cin >> x >> y;
//   std::cout << "the muliplication of " << x << " and " << y << " is " << x * y << std::endl;
//   return 0;
// }

// 1.8
int main()
{
  std::cout << "/*";
  std::cout << "*/";
  // std::cout << /* "*/"*/;
  std::cout << /* "*/" /* "/*" */;
}