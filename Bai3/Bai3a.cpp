#include <iostream> 
#include <math.h>
  using namespace std;
struct Phanso {
  int tu;
  int mau;
};
void inputPS(Phanso & a) {
  cout << "nhap tu: ";
  cin >> a.tu;
  cout << "nhap mau:";
  cin >> a.mau;
}
void outputPS(Phanso a) {
  cout << a.tu << "/" << a.mau << endl;
}
int UCLN(int a, int b) {
  a = abs(a);
  b = abs(b);
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}
Phanso RutGonPS(Phanso a) {

  Phanso x;
  int c = UCLN(a.tu, a.mau);
  x.tu = a.tu / c;
  x.mau = a.mau / c;
  return x;
}

int main(int argc, char
  const * argv[]) {
  Phanso a;
  inputPS(a);
  outputPS(a);
  cout << "phan so sau khi rut gon: ";
  Phanso x = RutGonPS(a);
  outputPS(x);
  return 0;
}
