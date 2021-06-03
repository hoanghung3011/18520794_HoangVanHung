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

void quyDong(Phanso & a, Phanso & b) {
  if (a.mau == b.mau) return;

  a.mau = a.mau * b.mau;
  b.mau = a.mau;

  a.tu = a.tu * b.mau;
  b.tu = b.tu * a.mau;

}
void max(Phanso a, Phanso b) {

  int c, d;
  c = a.tu * b.mau;
  d = b.tu * a.mau;

  cout << "phan so lon nhat la: ";
  if (c > d) {
    outputPS(a);
    return;
  }
  outputPS(b);
}
Phanso tong(Phanso a, Phanso b) {
  quyDong(a, b);
  Phanso c;
  c.tu = a.tu + b.tu;
  c.mau = a.mau;
  return c;
}
Phanso hieu(Phanso a, Phanso b) {
  quyDong(a, b);
  Phanso c;
  c.tu = a.tu - b.tu;
  c.mau = a.mau;
  return c;
}
Phanso tich(Phanso a, Phanso b) {
  Phanso c;
  c.tu = a.tu * b.tu;
  c.mau = a.mau * b.mau;
  return c;
}
Phanso thuong(Phanso a, Phanso b) {
  Phanso c;
  c.tu = a.tu * b.mau;
  c.mau = a.mau * b.tu;
  return c;
}

int main() {
  Phanso a, b;
  inputPS(a);
  inputPS(b);
  max(a, b);
  Phanso c = tong(a, b);
  cout << "tong 2 phan so la: ";
  outputPS(c);
  c = hieu(a, b);
  cout << "hieu 2 phan so la: ";
  outputPS(c);
  c = tich(a, b);
  cout << "tich 2 phan so la: ";
  outputPS(c);
  c = thuong(a, b);
  cout << "thuong 2 phan so la: ";
  outputPS(c);
}
