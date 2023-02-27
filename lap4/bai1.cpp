#include <iostream>
#include <string.h>
using namespace std;

#define nam_hien_tai 2022

struct ngay_sinh
{
    int ng,th,n;
};

class benh_nhan
{
    string ten,que_quan;
    ngay_sinh ns;
    public:
    benh_nhan(){
        ten = que_quan = "";
        ns.ng = ns.th = ns.n = 0;
    }
    benh_nhan(string ten, string que_quan, ngay_sinh ns)
    {
        ten = que_quan = "";
        ns.ng = ns.th = ns.n = 0;
    }
    void nhap()
    {   
        cin.ignore();
        cout << "Nhap vao ten benh nhan: ";
        getline(cin,ten);
        cout << "Nhap vao que quan: ";
        getline(cin,que_quan);
        cout << "Nhap vao ngay thang nam sinh: ";
        cin >> ns.ng >> ns.th >> ns.n;
    }
    void xuat()
    {
        cout << "Ten benh nhan: " << ten << endl;
        cout << "Que quan: " << que_quan << endl;
        cout << "Ngay sinh: " << ns.ng << "/" << ns.th << "/" << ns.n << endl;
    }
    int getnsn(){
        return ns.n;
    }
};
class benh_an : public benh_nhan
{
    string ten_benh_an;
    float vien_phi;
    public:
    benh_an() : benh_nhan()
    {
        ten_benh_an = "";
        vien_phi = 0;
    }
    benh_an(string ten, string que_quan, ngay_sinh ns,string ten_benh_an,float vien_phi) : benh_nhan(ten,que_quan, ns)
    {
        ten_benh_an = "";
        vien_phi = 0;
    } 
    void nhap()
    {
        benh_nhan :: nhap();
        cin.ignore();
        cout << "Nhap vao ten benh an: ";
        getline(cin,ten_benh_an);
        cout << "Nhap vao so tien vien phi: ";
        cin >> vien_phi;
        cout << endl << endl<< endl;
    }    
	int tuoi()
    {
        return (nam_hien_tai - getnsn());
    }  
    void xuat()
    {
        benh_nhan :: xuat();
        cout << "Ten benh an: " << ten_benh_an << endl;
        cout << "Vien phi: " << vien_phi << endl;
        cout << "Benh nhan " << tuoi() << " Tuoi" << endl<< endl;
    }
    float getvien_phi()
	{
    	return vien_phi;	
	}  
    bool operator>(const benh_an &a)
    {
        if(this -> vien_phi > a.vien_phi)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

    void bublesort(benh_an a[],int n)
    {	
        for(int i  = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j].tuoi() < a[j + 1].tuoi())
                swap(a[j], a[j + 1]);

    }

int main()
{
    benh_an a[100];
    int n;
    cout << "Nhap vao so luong benh nhan: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    for(int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    cout << "Sap Xep: \n";  
    bublesort(a,n);
    for(int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    cout << "Benh nhan co tuoi > 50: \n\n";
    for(int i = 0; i < n; i++)
    {
        if(a[i].tuoi() > 50)
        {
            a[i].xuat();
        }
    }
    benh_an max = a[0];
    for(int i = 0; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    cout << "Xuat vien phi max: ";
    max.xuat();
    return 0; 
}      
