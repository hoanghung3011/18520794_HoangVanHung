#include <iostream>
  using namespace std;

typedef struct Date {
  int dd;
  int mm;
  int yyyy;
}
D;

void InputDate(D & );
void OutputDate(D);
D NextDate(D & );

int main() {
  D a;

  cout << "Input Date:" << endl;
  InputDate(a);
  cout << "\n\nNext Date: ";
  OutputDate(NextDate(a));

  system("pause");
}

void InputDate(D & a) {
  int x;
  do {
    cout << "Day: ";
    cin >> a.dd;
    cout << "Month: ";
    cin >> a.mm;
    cout << "Year: ";
    cin >> a.yyyy;

    switch (a.mm) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      x = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      x = 30;
      break;
    case 2:
      if ((a.yyyy % 400 == 0) || (a.yyyy % 4 == 0 && a.yyyy % 100 != 0))
        x = 29;
      else
        x = 28;
      break;
    default:
      x = 0;
    }
    if (x == 0 || a.dd <= 0 || a.dd > x)
      cout << "\nEror! Please Input Date." << endl;
  } while (x == 0 || a.dd <= 0 || a.dd > x);
}
void OutputDate(D a) {
  cout << a.dd << " / " << a.mm << " / " << a.yyyy << endl;
}
D NextDate(D & a) {
  int x;
  switch (a.mm) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    x = 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    x = 30;
    break;
  case 2:
    if ((a.yyyy % 400 == 0) || (a.yyyy % 4 == 0 && a.yyyy % 100 != 0))
      x = 29;
    else
      x = 28;
    break;
  }
  if (a.dd == x) {
    a.dd = 1;
    if (a.mm == 12) {
      a.mm = 1;
      a.yyyy++;
    } else
      a.mm++;
  } else
    a.dd++;
  return a;
}
