#include <iostream>
#include <string.h>
using namespace std;


class hang_hoa
{
    string ma_hang,ten_hang;
    float don_gia;
    public:
    hang_hoa(){
        ma_hang = ten_hang = "";
        don_gia = 0;
    }
    hang_hoa(string ma_hang, string ten_hang, float don_gia)
    {
        ma_hang = ten_hang = "";
        don_gia = 0;
    }
    float getdon_gia()
	{
		return don_gia;
	 } 
    string getma_hang()
    {
        return ma_hang;
    }
    void nhap()
    {
        cout << "Nhap vao ma_hang : ";
        getline(cin,ma_hang);
        cout << "Nhap vao ten hang: ";
        getline(cin,ten_hang);
        cout << "Nhap vao don gia: ";
        cin >> don_gia;
    }
    void Xuat()
    {
        cout << "Ma hang: " << ma_hang<< endl ;
        cout << "Ten hang: " << ten_hang<< endl;
        cout << "Don gia: " << don_gia<< endl;
    }
};


class MT : public hang_hoa
{
    float toc_do;
    int sl;

    public:
    MT() : hang_hoa()
    {
        toc_do = 0;
        sl = 0;
    }
    MT(string ma_hang, string ten_hang,float don_gia,float toc_do,int sl) : hang_hoa(ma_hang,ten_hang, don_gia)
    {
        this -> toc_do = toc_do;
        this -> sl = sl;
    } 
    int thanh_tien()
    {
        return getdon_gia() * sl;
    }

    friend istream& operator>> (istream &is, MT &a);
    friend ostream& operator<< (ostream &os, MT &a);

};
istream& operator>> (istream &is, MT &a)
 {
    a.nhap();
    is.ignore();
    cout << "Nhap vao toc do: ";
    is >> a.toc_do;
    cout << "Nhap vao so luong: ";
    is >> a.sl;
    return is;
 }
ostream& operator<< (ostream &os, MT &a)
{
	a.Xuat();
    os << "Toc do: " << a.toc_do << endl;
    os << "So luong: " << a.sl << endl;
    os << "Thanh tien: " << a.thanh_tien() << endl;
    return os;
}

class MTXT : public MT
{
    private:
        float trong_luong;
    public:
         MTXT()
         {
            trong_luong = 0;
         }
         MTXT(float toc_do,int sl,float trong_luong) : MT(toc_do,sl)
         {
            this -> trong_luong = trong_luong;
         }
         
};
int main()
{
    MT a[100];
    int n;
    cout << "Nhap vao so luong benh nhan: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
		cin.ignore();
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    string s = "NO1";
    cout << "In san pham co ma hang khac NO1: \n\n\n";
    for(int i = 0; i < n; i++)
    {   
        if(a[i] != s)
        cout << a[i];
    }
}