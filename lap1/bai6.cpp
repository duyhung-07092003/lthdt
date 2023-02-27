#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class CN{
	private: 
		char *ht, *qq;
		int tuoi;
		float bl;
	public:
	
	CN()
		{
		ht=NULL; 
		tuoi=0;
		qq=NULL;
		bl=0;
		}
	CN(char *hten,int t,char *quequan,float bluong)
		{
			int n = strlen(hten);
			ht = new char[n+1];
			strcpy(ht, hten);
			
			tuoi= t;
			
			int m = strlen(quequan);
			qq = new char[m+1];
			strcpy(qq, quequan);
			
			bl=bluong;
		}
	~ CN() 
	   {
		if (ht!=NULL)
					delete ht;
		    
    	if (qq!=NULL)
					delete qq;
			tuoi=0;
    		bl=0;
	   }
    float tinhtl()
    {
    	return bl*250 + (bl*250)*0.2;	
	}
	void in()
	{
	cout<<this->ht<<"\t"<<this->tuoi<<"\t"<<this->qq <<"\t"<<this->bl<<"\t"<<this->tinhtl();
	cout<<endl;
	}
};

int main()
{
    CN x("duy hung",20,"tam hiep",12.23);
    x.in();
    
}