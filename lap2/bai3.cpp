#include<iostream>
#include <string.h>
using namespace std;
class TS {
private:
	char ten[30];
	float Toan, Van;
public:
	TS(){
		strcpy(this->ten , " ");
		this->Toan = 0;
		this->Van = 0;
	}
	TS(char ten[], float Toan, float Van){
		strcpy(this->ten, ten);
		this->Toan = Toan;
		this->Van = Van;
	}
	~TS(){

	}
	void Nhap(){
		cout << " \t [+] Ho va ten : " ;
		cin.getline(ten,30);
		cout << " \t [+] Toan : ";
		cin >> Toan;
		cout << " \t [+] Van : ";
		cin >> Van;
	}
	void Xuat (){
		cout << " \t [+] Ho va ten : " << ten << endl;
		cout << " \t [+] Toan : " << Toan << endl;
		cout << " \t [+] Van : " << Van << endl;
	}

	char *getTen(){
		return ten;
	}
	 

};

main(){
	TS x[100];
	int n ;
	cout << " [+] Hay nhap vao so thi sinh can nhap thong tin : ";
	cin >> n;
	cout << " A. NHAP THONG TIN THI SINH" << endl;
	for(int i = 0 ; i < n ; i++){
		cout << " [+] Nhap thong tin thi sinh thu : " << i+1 << endl;
		cin.ignore();
		x[i].Nhap();
		cout << endl;
	}
	cout << " B. XUAT THONG TIN THI SINH" << endl;
	for(int i = 0 ; i < n ; i++){
		cout << " [+] Xuat thong tin thi sinh thu : " << i+1 << endl;
		x[i].Xuat();
		cout << endl;
	}
	cout << " C. KIEM TRA THI SINH CO TON TAI TREN HE THONG HAY KHONG" << endl;
	char hoten[30];
	int h;
	cout << " [+] Nhap vao ten thi sinh can tim : ";
	cin.ignore();
	cin.getline(hoten,30);
	int dem = 0;
	for(int i = 0 ; i < n ; i++){
		if(strcmpi(x[i].getTen(), hoten) == 0){
			cout << " Thi sinh ton tai trong he thong !" << endl;
			h = i;
			x[i].Xuat();
			dem++;
		}
		if(i == n-1 && dem == 0 ) cout << " => Thi sinh khong ton tai trong he thong !" << endl;
	}
	for(int i = 0 ; i < n ; i++){
		if(i == h){
			for(int j = i; j < n - 1; j++){
        		x[j] = x[j+1];
    		}
    		n--;
    		cout << " -> Xoa thanh cong " << endl;
		}
	}
	cout << " D. XUAT THONG TIN THI SINH SAU KHI XOA" << endl;
	for(int i = 0 ; i < n ; i++){
		cout << " [+] Xuat thong tin thi sinh thu : " << i+1 << endl;
		x[i].Xuat();
		cout << endl;
	}
	cout << " E. SAP XEP DANH SACH " << endl;
	for(int i = 0 ; i < n-1 ; i++){
		for(int j = i+1; j < n ; j++){
			if(strcmpi(x[i].getTen(),x[j].getTen()) > 0){
				swap(x[i],x[j]);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout << " [+] Xuat thong tin thi sinh thu : " << i+1 << endl;
		x[i].Xuat();
		cout << endl;
	}
}