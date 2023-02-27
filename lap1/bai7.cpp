#include<algorithm>
#include <iostream>

using namespace std;

class giao_vien
{
    private:
        char ht[30];
        int t;
        char bc[15];
        char cn[20];
        float bl;
    public:
    double lcb;
    void nhap();
    void in();
    void tinh();
    float getbl();
    string getcn();
};

    void giao_vien :: nhap()
    {
        cin.ignore();
        cout << "Nhap vao ten giao vien: "; cin.getline(ht,30);
        cout << "Nhap vao tuoi: "; cin >> t;
        cout << "Nhap vao bang cap: "; cin.getline(bc,10);
        cout << "Nhap vao chuyen nganh: "; cin.getline(cn,20);
        cout << "Nhap vao bac luong: "; cin >> bl;
    }

    void giao_vien :: in()
    {
        cout << "Ten giao vien: " << ht << endl;
        cout << "Tuoi: " << t << endl;
        cout << "Bang cap: " << bc << endl;
        cout << "Chuyen nganh: " << cn << endl;
        cout << "Bac luong: " << bl << endl;
    }
    float giao_vien :: getbl()
    {
        return bl;
    }
    void giao_vien :: tinh()
    {
        lcb = getbl() * 610;
    }
    string giao_vien :: getcn()
    {
        return cn;
    }
    // bool cmp (giao_vien a, giao_vien b)
    // {
    //     return a.getcn() > b.getcn();
    // }
int main()
{   
    
    int n;
    cout << "Nhap vao so giao vien: ";
    cin >> n;
    giao_vien a[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap vao thong tin giao vien so " << i << ": \n";
        a[i].nhap();
    }
    for(int i = 0; i < n; i++)
    {
        a[i].in();
    }
    for(int i = 0; i < n; i++)
    {
        a[i].tinh();
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i].lcb < 2000)
        {
            a[i].in();
        }
    }
    // sort(a, a+n, cmp);
    // for(int i = 0; i < n; i++)
    // {
    //     a[i].in();
    // }
}