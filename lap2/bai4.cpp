#include <iostream>
#include <string.h>

using namespace std;

struct SV
{
        int bd;
        string hten;
        float t;
        float l;
        float h;
        float tong;
};


class SVien
{
    private: 
        SV *sv;
        int sosv;
    public:
        SVien()
        {
            sv = NULL;
            sosv = 0;
        }
        SVien(int n)
        {
            sv = new SV[n +1];
            sosv = n;
        }
        ~SVien()
        {
            if(sosv)
            {
                sosv = 0;
                sv = NULL;
            }
        };
        void Nhap()
        {
            if(sosv)
            {
                for(int i = 0; i < sosv; i++)
                {
                    cout << "Nhap sinh vien thu " << i + 1 << endl;
                    cout << "Nhap vao so bao danh: ";
                    cin >> sv[i].bd;
                    cout << "Nhap vao ho ten: ";
                    cin >> sv[i].hten;
                    cout << "Nhap vao diem toan: ";
                    cin >> sv[i].t;
                    cout << "Nhap vao diem hoa: ";
                    cin >> sv[i].h;
                    cout << "Nhap vao diem ly: ";
                    cin >> sv[i].l;
                    sv[i].tong = sv[i].t + sv[i].h + sv[i].l;
                }
            }

        }

        void Xuat()
        {
            if(sosv)
            {
                for(int i = 0; i < sosv; i++)
                {
                    cout << "Ho ten: " << sv[i].hten << endl;
                    cout << "So bao danh: " << sv[i].bd << endl;
                    cout << "Diem toan ly hoa: " << sv[i].t << sv[i].l << sv[i].h << endl;
                    cout << "Tong diem: " << sv[i].tong << endl;
                }
        
            }
        }
        void trung_tuyen()
        {
                for(int i = 0; i < sosv; i++)
                {
                    if(sv[i].tong >= 20)
                    {
                        cout << "Ho ten: " << sv[i].hten << endl;
                        cout << "So bao danh: " << sv[i].bd << endl;
                        cout << "Diem toan ly hoa: " << sv[i].t << sv[i].l << sv[i].h << endl;
                        cout << "Tong diem: " << sv[i].tong << endl;
                    }
                }
        }
        void thu_khoa()
        {
            float max;
            max = sv[0].tong;
            int k = 0;
            for(int i = 0; i < sosv; i++)
            {
                if(max < sv[i].tong)
                {
                    max = sv[i].tong;
                    k = i;
                }
            }
             cout << "Ho ten: " << sv[k].hten << endl;
                        cout << "So bao danh: " << sv[k].bd << endl;
                        cout << "Diem toan ly hoa: " << sv[k].t << sv[k].l << sv[k].h << endl;
                        cout << "Tong diem: " << sv[k].tong << endl;
        }

};
int main()
{
    int n;
    cout << "Nhap vao so sinh vien: ";
    cin >> n;
    SVien *a = new SVien(n);
    cout << "Nhap vao thong tin sinh vien: " << endl;
    a -> Nhap();
    cout << "Thong tin sinh vien: " << endl;
    a -> Xuat();
    cout << "Sinh vien trung tuyen: " << endl;
    a -> trung_tuyen();
    cout << "Sinh vien thu khoa: " << endl;
    a -> thu_khoa();
    delete a;
    cout << endl;
}