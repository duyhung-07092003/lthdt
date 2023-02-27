#include <iostream>
using namespace std;

class PS {
    int tuSo, mauSo;
public:
    PS(int ts=1, int ms=1)
    {
        tuSo=ts;
        mauSo=ms;
    }
    ~PS(){}
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        cout << "Nhap mau so: ";
        cin >> mauSo;
    }
    void rutGon() {
        int a = tuSo, b = mauSo;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        tuSo /= a;
        mauSo /= a;
    }
    void hienThi() {
        cout << tuSo << "/" << mauSo << endl;
    }
    PS operator+(const PS &b) {
        PS c;
        c.tuSo = tuSo * b.mauSo + mauSo * b.tuSo;
        c.mauSo = mauSo * b.mauSo;
        return c;
    }
    PS operator*(const PS &b) {
        PS c;
        c.tuSo = tuSo * b.tuSo;
        c.mauSo = mauSo * b.mauSo;
        return c;
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PS arr[50];
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        arr[i].nhap();
        arr[i].rutGon();
    }
    PS tong, tich;
    for (int i = 0; i < n; i++) {
        tong = tong + arr[i];
        tich = tich * arr[i];
    }
    cout << "Tong cua cac phan so la: ";
    tong.rutGon();
    tong.hienThi();
    cout << "Tich cua cac phan so la: ";
    tich.rutGon();
    tich.hienThi();
    return 0;
}