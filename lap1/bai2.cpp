#include <iostream>
using namespace std;

class Da_thuc2
{
    private:
        int a,b,c;
    public:
        Da_thuc2(int a = 0,int b = 0,int c =0)
        {
            this -> a = a;
            this -> b = b;
            this -> c = c;
        }
        ~Da_thuc2()
        {

        }
        void Xuat()
        {
            cout << a << "x^2";
            if(b >= 0)
            {
                cout << "+" << b << "x";
            }
            else
            {
                cout << b << "x";
            }
            if(c >= 0)
            {
                cout << "+" << c;
            }
            else
            {
                cout << c;
            }
        }
            Da_thuc2 tong(Da_thuc2 &dt)
            {
                Da_thuc2 t;
                t.a = a + dt.a;
                t.b = b + dt.b;
                t.c = c + dt.c;
                return t;
            }
        
};
int main()
{
    Da_thuc2 dt1(5,7,9);
    Da_thuc2 dt2(1,2,3);
    Da_thuc2 tong1;
    tong1 = dt1.tong(dt2);
    cout << "Tong 2 da thuc: " << endl;
    tong1.Xuat();
    cout << endl;
}