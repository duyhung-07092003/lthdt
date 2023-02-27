#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class MAYTINH {
    private:
        char ma[30];
        int t;
        char ten_hang[15];
        char cn[20];
        float don_gia;
    public:
        MAYTINH(char* ten="", int tuoi=0, char* bang="",char* nganh="",float bac=0)
        {
            strcpy(this->ma,ten);
            this->t=tuoi;
            strcpy(this->ten_hang,bang);
            strcpy(this->cn,nganh);
            this->don_gia=bac;
        }
        friend istream& operator >> (istream& is, MAYTINH& MAYTINH);
        float tinh_luong_cb();
        char* getma()
        {
            return this->ma;
        }
        friend ostream& operator << (ostream& os, MAYTINH& MAYTINH);
};

istream& operator >> (istream& is, MAYTINH& MAYTINH) {
    fflush(stdin);
    cout << "\tNhap ho ten: "; is.getline(MAYTINH.ma, 30);
    cout << "\tNhap tuoi: "; is >> MAYTINH.t;
    fflush(stdin);
    cout << "\tNhap bang cap: "; is.getline(MAYTINH.ten_hang, 15);
    cout << "\tNhap chuyen nganh: "; is.getline(MAYTINH.cn, 20);
    cout << "\tNhap bac luong: "; is >> MAYTINH.don_gia;
    return is;
}

ostream& operator << (ostream& os,MAYTINH& MAYTINH) {
    os << "|" <<setw(30)<< MAYTINH.ma << "|";
    os << setw(10) << MAYTINH.t << "|";
    os << setw(15) << MAYTINH.ten_hang << "|";
    os << setw(20) << MAYTINH.cn << "|";
    os << setw(10) << MAYTINH.don_gia << "|";
    os << setw(10) << MAYTINH.tinh_luong_cb()<<"|\n";
    return os;
}

float MAYTINH::tinh_luong_cb() {
    return don_gia * 610;
}
void tieude()
{
    cout << "|" <<setw(30)<< "Ho va ten" << "|";
    cout << setw(10) << "Tuoi" << "|";
    cout << setw(15) << "Bang cap" << "|";
    cout << setw(20) << "Chuyen nganh" << "|";
    cout << setw(10) << "Bac luong" << "|";
    cout << setw(10) << "Luong" <<"|\n";
}
int main() 
{
    int n;
    cout << "Nhap so luong giao vien: ";
    cin >> n;

    MAYTINH MAYTINH[1000];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin giao vien thu " << i+1 << endl;
        cin >> MAYTINH[i];
    }

    cout << "Danh sach giao vien co luong nho hon 2000:" << endl;
    tieude();
    for (int i = 0; i < n; i++) {
        if (MAYTINH[i].tinh_luong_cb() < 2000) {
            cout << MAYTINH[i];
        }
    }
    char ten[30];
    bool check = true;
    fflush(stdin);
    cout<<"Nhap ho va ten: "; cin.getline(ten,30);
    for(int i=0;i<n;i++)
        if(strcmpi(MAYTINH[i].getma(),ten)==0)
            {
                cout<<"Luong cua giao vien "<<ten<<" la: "<<MAYTINH[i].tinh_luong_cb();
                check = false;
            }
    if(check)
    {
        cout<<"Nhap thong tin giao vien tren:\n";
        cin>>MAYTINH[n];
        n++;
        cout << "\nDanh sach giao vien sau khi them: " << endl;
        tieude();
        for (int i = 0; i < n; i++) 
        {
            cout << MAYTINH[i];
        }
    }
    return 0;
}