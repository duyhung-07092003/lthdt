#include <iostream>
#include <math.h>

using namespace std;

int ucln(int a,int b)
{
    a = abs(a);
    b = abs(b);
    while(a != b)
    {
        if(a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

class ps
{
    private:
        float ts;
        float ms;
    public:
    ps(float tu_so = 0,float mau_so)
    {
        ts = tu_so;
        ms = mau_so;
    }
    ~ps()
    {
    }
    friend istream& operator >>(istream &is,ps &p)
    {
        cout << "Nhap vao tu so: ";
        is >> p.ts;
        cout << "Nhap mau so: "; 
        is >> p.ms;
        return is;
    }
    friend ostream& operator <<(ostream &os,ps &p)
    {
        os << p.ts << "/" << p.ms;
    }
    ps rut_gon()
    {
        ps p;
        p.ts = ts / ucln(ts,ms);
        p.ms = ms / ucln(ts,ms);
        return p;
    }
    ps operator + (ps &p)
    {
        ps phan_so;
        phan_so.ts = this -> ts * p.ms + p.ts * this -> ms;
        phan_so.ms = this -> ms * p.ms;
        return phan_so.rut_gon();
    }
};