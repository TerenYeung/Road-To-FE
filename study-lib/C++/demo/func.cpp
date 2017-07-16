int Add(int x, int y)
{
 int ret;
 ret = x + y;
 return ret; 
}

int Compare(int x, int y)
{
  int ret;
  if(x<y)
    ret = -1;
  else if (x=y)
    ret = 0;
  else
    ret = 1;
  return ret;
}

void Swap(int x, int y)
{
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
  return;
}

// 谓词函数
bool IsLeap(int year)
{
  int ret;
  ret = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  return ret;
}

// 素性判定函数第一版
bool isPrime( unsigned int n)
{
  unsigned int i = 2;
  while(i<n)
  {
    if(n % i == 0)
      return false;
    i++;
  }
  return true;
}

// 素性判定第二版
bool isPrime( unsigned int n)
{
  unsigned int i = 2;
  while(i <= (unsigned int)sqrt(n))
  {
    if ( n % i == 0)
     return false;
    i++;
  }
  return true;
}
// 素性判定第三版
bool isPrime( unsigned int n)
{
  unsigned int i = 3;
  if (n % 2 == 0)
    return false;
  while(i <= (unsigned int)sqrt(n))
  {
    if ( n % i == 0)
     return false;
    i += 2;
  }
  return true;
}

// 素性判定第四版
bool isPrime( unsigned int n)
{
  unsigned int i = 3, t = (unsigned int)sqrt(n) + 1;
  if (n % 2 == 0)
    return false;
  while(i <= t)
  {
    if ( n % i == 0)
     return false;
    i += 2;
  }
  return true;
}

// 求两个整整数的x与y的最大公约数
unsigned int gcd( unsigned int x, unsigned int y)
{
  unsigned int r;
  while(true)
  {
    r = x % y;
    if(r == 0)
      return y;
    x = y;
    y = r;
  }
}

// 阶乘函数
// 循环实现
unsigned int GetFactorial( unsigned int n)
{
  unsigned int result = 1, i = 0;
  while(++i < n)
    result *= i;
  return result;
}
// 递归实现
unsigned int GetFactorial( unsigned int n)
{
  unsigned int result;
  if(n == 1) result =1;
  else       result = n * GetFactorial(n-1);
  return result;
}

// 斐波那契数列函数
// 循环实现
unsigned int GetFibonacci(unsigned int n)
{
  unsigned int i, f1, f2, f3;
  if( n == 2 || n == 1) return 1;
  f1 = 1;
  f2 = 1;
  for(i = 3; i < n; i++)
  {
    f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
  }
  return f3;
}
// 递归实现
unsigned int GetFibonacci(unsigned int n)
{
  if( n == 2 || n == 1)
    return 1;
  else
    return GetFibonacci(n-1) + GetFibonacci(n-2);
}