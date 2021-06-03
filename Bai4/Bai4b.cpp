#include <iostream>
  using namespace std;
struct HOCSINH {
  char hoTen[40];
  float toan;
  float van;
  float diemTB;
};
int main() {
  HOCSINH a;
  cout << "nhap ho ten hs: ";
  cin.getline(a.hoTen, 40);
  cout << "nhap diem toan, van: ";
  cin >> a.toan >> a.van;
  a.diemTB = (a.toan + a.van) / 2;
  cout << "diem TB la: " << a.diemTB;
  return 0;
}
