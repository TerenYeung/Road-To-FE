# include <iostream>
# include <iomanip>
using namespace std;
typedef enum {
  SUN,
  MON,
  TUE,
  WED,
  THU,
  FRI,
  SAT
} WEEKDAY;

int main ()
{
  int date;
  const WEEKDAY date_1 = FRI;
  WEEKDAY weekday;
  cout << "The program gets a date(1~31), \n";
  cout << "and prints a calendar of 2006-12.\n";
  cout << "The date: ";
  cin >> date;
  if(date < 1 || date > 31){
    cout << "Date error!";
    return 1;
  }
  weekday = (WEEKDAY)((date + (int)date_1 - 1) % 7);
  cout << "Calendar 2006-12\n";
  cout << "----------------\n";
  cout << "Su Mo Tu We Th Fr Sa \n";
  cout << "----------------\n";
  if (weekday == SUN ) cout << setw(0) << date;
  else if(weekday == MON ) cout << setw(4) << date;
  else if(weekday == TUE) cout << setw(8) << date;
  else if(weekday == WED) cout << setw(12) << date;
  else if(weekday == TUE) cout << setw(16) << date;
  else if(weekday == FRI) cout << setw(20) << date;
  else cout << setw(26) << date;
  cout << endl << "---------------\n";
  return 0;
}