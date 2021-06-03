#include <iostream>
#include <string.h>
#include <string>
using namespace std;
struct Nhanvien {
  char manv[8];
  char hoten[20];
  char phongban[10];
  int luongcb;
  int thuong;
  int thuclanh;
};
void nhapnv(Nhanvien& a) {
  cin.ignore();
  cout << "\nNhap ma nhan vien: ";
  cin.getline(a.manv, 8);
  cout << "Nhap ho va ten nhan vien: ";
  cin.getline(a.hoten, 20);
  cout << "Nhap phong ban: ";
  cin.getline(a.phongban, 10);
  cout << "Nhap luong co ban: ";
  cin >> a.luongcb;
  cout << "Nhap thuong: ";
  cin >> a.thuong;
}
void xuatnv(Nhanvien a) {
  cout << "Ma nhan vien: " << a.manv << "\n";
  cout << "Ho va ten nhan vien: " << a.hoten << "\n";
  cout << "Phong ban: " << a.phongban << "\n";
  cout << "Luong co ban: " << a.luongcb << "\n";
  cout << "Thuong: " << a.thuong << "\n";
  a.thuclanh = a.luongcb + a.thuong;
  cout << "Thuc lanh: " << a.thuclanh << "\n";
}
void DSnhanvien(Nhanvien b[], int& n) {
  cout << "Nhap so phan tu: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Nhap nhan vien thu " << i + 1 << ":";
    nhapnv(b[i]);
  }
}
void XuatDS(Nhanvien b[], int n) {
  for (int i = 0; i < n; i++) {
    xuatnv(b[i]);
    cout << "---------------------------------- \n";
  }
}
int thuclanh(Nhanvien a) {
  a.thuclanh = a.luongcb + a.thuong;
  return a.thuclanh;
}
void tongthuclanh(Nhanvien b[], int n) {
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += thuclanh(b[i]);
  }
  cout << "Tong thuc lanh la: " << s << "\n";
}
void luongthapnhat(Nhanvien b[], int n) {
  Nhanvien min = b[0];
  for (int i = 0; i < n; i++) {
    if (b[i].luongcb < min.luongcb) {
      min = b[i];
    }
  }
  cout << "Nhan vien co muc luong thap nhat la: \n";
  cout << "Ma nhan vien: " << min.manv << "\n";
  cout << "Ho va ten nhan vien: " << min.hoten << "\n";
  cout << "Phong ban: " << min.phongban << "\n";
  cout << "Luong co ban: " << min.luongcb << "\n";
  cout << "Thuong: " << min.thuong << "\n";
  min.thuclanh = min.luongcb + min.thuong;
  cout << "Thuc lanh: " << min.thuclanh << "\n";
}
void demnv(Nhanvien b[], int n) {
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (b[i].thuong >= 1200000) dem++;
  }
  cout << "\nco " << dem << " nhan vien co muc thuong duoi 1200000 \n";
}
void swap(Nhanvien* x, Nhanvien* y) {
  Nhanvien t = *x;
  *x = *y;
  *y = t;
}
void sapxep(Nhanvien* b, int n) {
  struct Nhanvien t;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(b[i].phongban, b[j].phongban) > 0) {
        swap(&b[i], &b[j]);
      } else if (strcmp(b[i].phongban, b[j].phongban) == 0) {
        if (strcmp(b[i].manv, b[j].manv) > 0) {
          swap(&b[i], &b[j]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << "\nMa nhan vien: " << b[i].manv << "\n";
    cout << "Ho va ten nhan vien: " << b[i].hoten << "\n";
    cout << "Phong ban: " << b[i].phongban << "\n";
    cout << "Luong co ban: " << b[i].luongcb << "\n";
    cout << "Thuong: " << b[i].thuong << "\n";
    b[i].thuclanh = b[i].luongcb + b[i].thuong;
    cout << "Thuc lanh: " << b[i].thuclanh << "\n";
  }
}
int main() {
  Nhanvien b[50];
  int n;
  DSnhanvien(b, n);
  XuatDS(b, n);
  tongthuclanh(b, n);
  luongthapnhat(b, n);
  demnv(b, n);
  cout << "\nSau khi sap xep danh sach nhan vien la: ";
  sapxep(b, n);
  system("pause");
  return 0;
}