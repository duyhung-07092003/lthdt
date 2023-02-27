#include <iostream>
using namespace std;

class SP
{
    private:
        int pt;
        int pa;
    public:
        SP(int pt =0,int pa = 0)
        {
            this -> pt = pt;
            this -> pa = pa;
        }
        void in()
        {
            if(pa >= 0)
            {
                cout << pt << "+" << pa << "*j" << endl;
            }
            else
            {
                cout << pt << "-" << abs(pa) << "*j" << endl;
            }
        }
            SP tong_da_thuc(SP &p)
            {
                SP tong;
                tong.pt = this -> pt + p.pt;
                tong.pa = this -> pa + p.pa;
                return tong;
            }
        };
int main()
{
    SP p1(5,-8);
    SP p2(-7,3);
    SP p3(6,-9);
    SP p4,p5;
    p4 = p1.tong_da_thuc(p2);
    p5 = p3.tong_da_thuc(p4);
    cout << "Tong 3 da thuc la: ";
    p5.in();
    cout << endl;
    
}
