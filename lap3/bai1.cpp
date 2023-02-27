#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    float real,imag;
public:
    Complex(float thuc=0, float ao=0)
    {
        this->real=thuc;
        this->imag=ao;
    }
    ~Complex(){}
    friend istream& operator>>(istream& is, Complex &a)
    {
        cout<<"\tNhap phan thuc: "; is>>a.real;
        cout<<"\tNhap phan ao: "; is>>a.imag;
        return is;
    }
    friend ostream& operator<<(ostream& os, Complex &a)
    {
        os<<a.real;
        if(a.imag<0)
            os<<" - "<<fabs(a.imag)<<"i";
        else if(a.imag>0)
            os<<" + "<<fabs(a.imag)<<"i";
        return os;
    }
    Complex operator+(Complex x)
    {
        Complex res;
        res.real = this->real + x.real;
        res.imag = this->imag + x.imag;
        return res;
    }
    Complex operator-(Complex x)
    {
        Complex res;
        res.real = this->real - x.real;
        res.imag = this->imag - x.imag;
        return res;
    }
};
int main()
{
    Complex a,b;
    cout<<"Nhap so phuc a: \n";
    cin>>a;
    cout<<"Nhap so phuc b:\n";
    cin>>b;
    cout<<"So phuc a co dang: "<<a;
    cout<<"\nSo phuc b co dang: "<<b;
    Complex tong,hieu;
    tong = a+b;
    hieu = a-b;
    cout<<"Tong 2 so phuc: "<<tong;
    cout<<"\nHieu 2 so phuc: "<<hieu;
    return 0;
}