#include <iostream>
using namespace std;

class vector3
{
private:
	float a,b,c;
public:
	vector3(float aa=0, float bb=0, float cc=0)
	{
		this->a=aa;
		this->b=bb;
		this->c=cc;
	}
	~vector3(){}
	void nhap()
	{
		cout<<"\tNhap a = "; cin>>a;
		cout<<"\tNhap b = "; cin>>b;
		cout<<"\tNhap c = "; cin>>c;
	}
	void xuat()
	{
		cout<<"("<<a<<","<<b<<","<<c<<")"<<endl;
	}
	vector3 cong(vector3 x)
	{
		vector3 tong;
		tong.a= this->a+x.a;
		tong.b= this->b+x.b;
		tong.c= this->c+x.c;
		return tong;
	}
};
int main()
{
	vector3 x,y;
	cout<<"Nhap vector x:\n";
	x.nhap();
	cout<<"vector co dang: ";
	x.xuat();
	cout<<"Nhap vector y:\n";
	y.nhap();
	cout<<"vector co dang: ";
	y.xuat();
	cout<<"Tong 2 vector: ";
	x.cong(y).xuat();
	return 0;
}
