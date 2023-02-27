#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class GV {
    private:
        char ht[30];
        int t;
        char bc[15];
        char cn[20];
        float bl;
    public:
        GV(char* ten="", int tuoi=0, char* bang="",char* nganh="",float bac=0)
        {
            strcpy(this->ht,ten);
            this->t=tuoi;
            strcpy(this->bc,bang);
            strcpy(this->cn,nganh);
            this->bl=bac;
        }
        friend istream& operator >> (istream& is, GV& gv);
        float tinh_luong_cb();
        char* getht()
        {
            return this->ht;
        }
        friend ostream& operator << (ostream& os, GV& gv);
};

istream& operator >> (istream& is, GV& gv) {
    fflush(stdin);
    cout << "\tNhap ho ten: "; is.getline(gv.ht, 30);
    cout << "\tNhap tuoi: "; is >> gv.t;
    fflush(stdin);
    cout << "\tNhap bang cap: "; is.getline(gv.bc, 15);
    cout << "\tNhap chuyen nganh: "; is.getline(gv.cn, 20);
    cout << "\tNhap bac luong: "; is >> gv.bl;
    return is;
}

ostream& operator << (ostream& os,GV& gv) {
    os << "|" <<setw(30)<< gv.ht << "|";
    os << setw(10) << gv.t << "|";
    os << setw(15) << gv.bc << "|";
    os << setw(20) << gv.cn << "|";
    os << setw(10) << gv.bl << "|";
    os << setw(10) << gv.tinh_luong_cb()<<"|\n";
    return os;
}

float GV::tinh_luong_cb() {
    return bl * 610;
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

    GV gv[1000];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin giao vien thu " << i+1 << endl;
        cin >> gv[i];
    }

    cout << "Danh sach giao vien co luong nho hon 2000:" << endl;
    tieude();
    for (int i = 0; i < n; i++) {
        if (gv[i].tinh_luong_cb() < 2000) {
            cout << gv[i];
        }
    }
    char ten[30];
    bool check = true;
    fflush(stdin);
    cout<<"Nhap ho va ten: "; cin.getline(ten,30);
    for(int i=0;i<n;i++)
        if(strcmpi(gv[i].getht(),ten)==0)
            {
                cout<<"Luong cua giao vien "<<ten<<" la: "<<gv[i].tinh_luong_cb();
                check = false;
            }
    if(check)
    {
        cout<<"Nhap thong tin giao vien tren:\n";
        cin>>gv[n];
        n++;
        cout << "\nDanh sach giao vien sau khi them: " << endl;
        tieude();
        for (int i = 0; i < n; i++) 
        {
            cout << gv[i];
        }
    }
    return 0;
}