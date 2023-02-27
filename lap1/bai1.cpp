#include <iostream>
using namespace std;

class HCN
{
    private:
        float d,r;
    public:
        void nhap()
        {
            cout << "Nhap chieu dai: ";
            cin >> d;
            cout << "Nhap vao chieu rong: ";
            cin >> r;
        }
        void Xuat()
        {
            cout << "Chieu dai: " << d << "Chieu rong: " << r << endl;
        }
        double chu_vi()
        {
            return (d + r)*2;
        }
        double dien_tich()
        {
            return  d * r;
        }
};
int main()
{
    HCN *a;
    int n;
    cout << " Nhap so n : ";
    cin >> n;
    a = new HCN[n];
    cout << "Nhap vao thong tin hinh chu nhat: " << endl;
    for(int i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    cout << "Thong tin hcn: " << endl;
    for(int i = 0; i < n; i++)
    {
        a[i].Xuat();
    }
    float chu_vi_max = a[0].chu_vi();
    int cv_max = 0;
    for(int i  = 0; i < n; i++)
    {
        if(chu_vi_max < a[i].chu_vi())
        {
            chu_vi_max = a[i].chu_vi();
            cv_max = i;
        }
    }
    cout << "hcn co chu vi max: " << endl;
    a[cv_max].Xuat();
    float dien_tich_min = a[0].dien_tich();
    int dt_min = 0;
    for(int i  = 0; i < n; i++)
    {
        if(dien_tich_min > a[i].dien_tich())
        {
            dien_tich_min = a[i].dien_tich();
            dt_min = i;
        }
    }
    cout << "hcn co dien tich min: " << endl;
    a[dt_min].Xuat();
}