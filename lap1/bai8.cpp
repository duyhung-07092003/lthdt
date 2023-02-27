#include<iostream>
#include<string.h>
using namespace std;

struct ns
{
	int ngay,thang,nam;
};
class KH
{
private:
	char *hoten,*cmt,*hokhau;
	ns date;
public:
	KH()
	{
		this->hoten=NULL;
		this->cmt=NULL;
		this->hokhau=NULL;
		this->date.ngay=1;
		this->date.thang=1;
		this->date.nam=1;
	}
	KH(char *ht, char *cccd, char* hk, ns NGAY)
	{
		int m=strlen(ht);
		this->hoten= new char[m+1];
		strcpy(this->hoten,ht);
		int n=strlen(cccd);
		this->cmt= new char[n+1];
		strcpy(this->cmt,cccd);
		int k=strlen(hk);
		this->hokhau= new char[k+1];
		strcpy(this->hokhau,hk);
		this->date.ngay=NGAY.ngay;
		this->date.thang=NGAY.thang;
		this->date.nam=NGAY.nam;
	}
	~KH()
	{
		if(this->hoten!=NULL)
			delete this->hoten;
		if(this->cmt!=NULL)
			delete this->cmt;
		if(this->hokhau!=NULL)
			delete this->hokhau;
	}
	void xuat()
	{
		cout<<"Ho ten: "<<this->hoten<<endl;
		cout<<"Ngay sinh: "<<this->date.ngay<<"/"<<this->date.thang<<"/"<<this->date.nam<<endl;
		cout<<"So chung minh thu: "<<this->cmt<<endl;
		cout<<"Ho khau: "<<this->hokhau<<endl;
	}
};
int main()
{
	ns NGAY;
	NGAY.ngay=19;
	NGAY.thang=8;
	NGAY.nam=2000;
	KH kh("Nguyen Huynh Vy","001300002187","Thach That, Ha Noi",NGAY);
	kh.xuat();
	return 0;
}
