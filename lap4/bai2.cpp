#include <iostream>
#include <string.h>
using namespace std;

class my_date
{
    int d,m,y;
    public:
    my_date()
    {
        d = m = y = 0;
    }
    my_date(int d,int m,int y)
    {
        d = m = y = 0;
    }
    ~my_date()
    {
    }

    int gety()
    {
        return y;
    }

    void nhap()
    {
        cout << "Nhap vao Ngay Thang Nam: ";
        cin >> d >> m >> y;
    }
    void xuat()
    {
        cout << "Ngay Thang nam: "<< d << "/" << m << "/" << y << endl;
    }
};
class person : public my_date
{
    string name,address;
    int phone;
    public:    
    friend class my_date;
    person()
    {
        name = address = "";
        phone = 000000;
    }
    person(int d,int m,int y,string name,string address, int phone) : my_date(d,m,y)
    {
        name = address = "";
        phone = 000000;
    }
    ~person()
    {

    }
    void nhap()
    {
        my_date :: nhap();
        cin.ignore();
        cout << "Nhap vao ten: ";
        getline(cin,name);
        cout << "Nhap vao dia chi: ";
        getline(cin,address);
        cout << "Nhap std: ";
        cin >> phone;
    }
    void xuat()
    {
        my_date :: xuat();
        cout << "Ten: " << name << endl;
        cout << "Dia Chi: " << address << endl;
        cout << "SDT: " << phone << endl << endl;
    }
};
    bool operator > (person a,person b)
    {
        return a.gety() > b.gety();
    }
    void bublesort(person a[],int n)
    {
        for(int i  = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    }

int main()
{
    person a[100];
    int n;
    cout << "Nhap vao so luong person : ";
    cin >> n;
     for(int i  = 0; i < n ; i++)
     {
        a[i].nhap();
     }
     bublesort(a,n);
     cout << "Sap Xep: \n\n";
    for(int i  = 0; i < n ; i++)
     {
        a[i].xuat();
     }


}