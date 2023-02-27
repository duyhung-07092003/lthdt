#include <iostream>
#include <math.h>
using namespace std;

class  Dathuc3
{
private:
    int a,b,c,d;
public:
    Dathuc3(int aa=1,int bb=0,int cc=0,int dd=0)
    {
        this->a=aa;
        this->b=bb;
        this->c=cc;
        this->d=dd;
    }
    friend istream& operator>>(istream& is,Dathuc3 &x)
    {
        loop:
        cout<<"\tNhap he so bac 3: "; is>>x.a;
        if(x.a==0)
        {
            cout<<"Day khong phai la Da thuc bac 3, vui long:\n";
            goto loop;
        }
        cout<<"\tNhap he so bac 2: "; is>>x.b;
        cout<<"\tNhap he so bac 1: "; is>>x.c;
        cout<<"\tNhap he so bac 0: "; is>>x.d;
        return is;
    }
    friend ostream& operator<<(ostream& os, Dathuc3 &x)
    {
        os<<x.a<<"x^3";
        if(x.b<0)
            os<<" - "<<abs(x.b)<<"x^2";
        else if(x.b>0)
            os<<" + "<<x.b<<"x^2";
        if(x.c<0)
            os<<" - "<<abs(x.c)<<"x";
        else if(x.c>0)
            os<<" + "<<x.c<<"x";
        if(x.d<0)
            os<<" - "<<abs(x.d);
        else if(x.d>0)
            os<<" + "<<x.d;
        return os;
    }
    Dathuc3 operator+(Dathuc3 x)
    {
        Dathuc3 res;
        res.a=this->a + x.a;
        res.b=this->b + x.b;
        res.c=this->c + x.c;
        res.d=this->d + x.d;
        return res;
    }
    Dathuc3 operator-(Dathuc3 x)
    {
        Dathuc3 res;
        res.a=this->a - x.a;
        res.b=this->b - x.b;
        res.c=this->c - x.c;
        res.d=this->d - x.d;
        return res;
    }
};
int main()
{
    Dathuc3 dt1,dt2;
    cout<<"Nhap da thuc thu nhat:\n"; cin>>dt1;
    cout<<"Nhap da thuc thu hai:\n"; cin>>dt2;
    cout<<"\nDa thuc thu nhat co dang: "<<dt1;
    cout<<"\nDa thuc thu hai co dang: "<<dt2;
    Dathuc3 tong,hieu;
    tong = dt1 + dt2;
    hieu = dt1 - dt2;
    cout<<"\nTong hai da thuc: "<<tong;
    cout<<"\nHieu hai da thuc: "<<hieu;
    return 0;
}