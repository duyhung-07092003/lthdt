#include <iostream>
#include <string.h>
using namespace std;

class mat_hang
{
    string ma_hang,ten_hang;
    float don_gia;
    public:
    mat_hang(){
        ma_hang = ten_hang = "";
        don_gia = 0;
    }
    mat_hang(string ma_hang, string ten_hang, float don_gia)
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
    friend istream& operator>> (istream &is, mat_hang &a);
     friend ostream& operator<< (ostream &os, mat_hang &a);
};


istream& operator>> (istream &is, mat_hang &a)
    {
		
        cout << "Nhap vao ma_hang : ";
        getline(is,a.ma_hang);
        cout << "Nhap vao ten hang: ";
        getline(is,a.ten_hang);
        cout << "Nhap vao don gia: ";
        is >> a.don_gia;
        return is;
    }
ostream& operator<< (ostream &os, mat_hang &a)
{
	os<< "Ma hang: " << a.ma_hang<< endl ;
    os << "Ten hang: " << a.ten_hang<< endl;
    os << "Don gia: " << a.don_gia<< endl;
}
  bool operator!=(mat_hang &c,string s)
    {
    if(c.getma_hang() != s)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
class banh_keo : public mat_hang
{
    string noi_san_xuat;
    public:
    banh_keo() : mat_hang()
    {
        noi_san_xuat = "";
    }
    banh_keo(string ma_hang, string ten_hang,float don_gia,string noi_san_xuat) : mat_hang(ma_hang,ten_hang, don_gia)
    {
        noi_san_xuat = "";
    } 
    int chiet_khau()
    {
        return getdon_gia() * 0.01;
    }

    friend istream& operator>> (istream &is, banh_keo &a);
    friend ostream& operator<< (ostream &os, banh_keo &a);

};
istream& operator>> (istream &is, banh_keo &a)
 {
    
    is >> (mat_hang &)a;is.ignore();
    cout << "Nhap vao noi san xuat: ";
    getline(is,a.noi_san_xuat);
 }
ostream& operator<< (ostream &os, banh_keo &a)
{
	os << (mat_hang &)a;
    os << "Noi san xuat: " << a.noi_san_xuat << endl;
}
int main()
{
    banh_keo a[100];
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