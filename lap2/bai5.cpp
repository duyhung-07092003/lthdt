#include <iostream>
#include <string.h>
using namespace std;

class NGUOI
{
     private:
        char ht [30];
        int tuoi;
        char nghenghiep[30];
        char quoctich[30];
    public:
        NGUOI()
        {
            strcmp(this->ht," ");
            this->tuoi = 0;
            strcmp(this->nghenghiep," ");
            strcmp(this->quoctich," ");
        }
        NGUOI(char ht[30], int tuoi, char nghenghiep[30], char quoctich[30])
        {
            strcmp(this->ht,"ht");
            this->tuoi = tuoi;
            strcmp(this->nghenghiep,"nghenghiep");
            strcmp(this->quoctich,"quoctich");
        }
        ~NGUOI()
        {
            strcmp(this->ht,"ht");
            this->tuoi = tuoi;
            strcmp(this->nghenghiep,"nghenghiep");
            strcmp(this->quoctich,"quoctich");
        }
        void Nhap()
        {
            cin.ignore();
            cout <<" [+] Nhap vao ho ten: ";
            cin.getline(ht, 30);
            cout <<"  +  Nhap vao nghe nghiep: ";
            cin.getline(nghenghiep, 30);
            cout <<"  +  Nhap vao quoc tich: ";
            cin.getline(quoctich, 30);
            cout <<"  +  Nhap vao tuoi: ";
            cin >>tuoi;
        }

        void Xuat()
        {
            cout <<" [+] Ho ten: "<<ht<<endl;
            cout <<"  +  Tuoi: "<<tuoi<<endl;
            cout <<"  +  Nghe nghiep: "<<nghenghiep<<endl;
            cout <<"  +  Quoc tich: "<<quoctich<<endl;
        }
        char *getht()
        {
            return ht;
        }
        char *getnghenghiep()
        {
            return nghenghiep;
        }
        char *getquoctich()
        {
            return quoctich;
        }
        int gettuoi()
        {
            return tuoi;
        }
};
int main()
{
    NGUOI a[100];
    int n;
    cout <<" [?] Nhap vao so nguoi: ";
    cin >>n;
    for(int i=0; i<n; i++)
    {
        cout <<" [?] Nhap vao thong tin cua nguoi thu "<<i+1<<":"<<endl;
        a[i].Nhap();
    }
    cout <<"\n --- DANH SACH NGUOI --- "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j= i+1; j<n; j++)
        {
            if(strcmpi(a[i].getht(),a[j].getht()) > 0)
            swap(a[i], a[j]);
        }
        a[i].Xuat();    
    }
    char bs[30] = "bac sy";
    cout <<"\n --- DANH SACH NGHE NGHIEP BAC SY --- "<<endl;
    for(int i=0; i<n; i++)
    {
        if(strcmpi(a[i].getnghenghiep(), bs ) == 0)
        a[i].Xuat();    
    }
    char qt[30] = "Campuchia";
    int chiso;
    int dem =0;
    cout <<"\n --- DANH SACH SAU KHI XOA NGUOI CAMPUCHIA --- "<<endl;
    for(int i=0; i<n; i++)
    {
        if(strcmpi(a[i].getquoctich(), qt ) == 0)
        chiso = i;
        dem++; 
    }
    for(int i = 0 ; i < n ; i++){
		if(i == chiso){
			for(int j = i; j < n - 1; j++){
        		a[j] = a[j+1];
    		}
    		n--;
		}
        a[i].Xuat();
	}
	char K[30] = "Le Dai Nghia";
    cout <<"\n --- DANH SACH SAU KHI CHEN THEM NGUOI NAY VAO CUOI DS --- "<<endl;
    for(int i=0; i<n; i++)
    {
        if(strcmpi(a[i].getht(),K ) == 0)
		{
			cout << " -Ten da co trong danh sach !!! " << endl;
		}
		else
		{
			n++;
            a[i].Nhap();
			strcpy(a[n - 1].getht(), K);
            a[i].Xuat();

		}
        
    }
    for(int i = 0 ; i < n ; i++){
		
        a[i].Xuat();
	}
    int max = a[0].gettuoi();
    int chisomax = 0, chisomin = 0;
    int min = a[0].gettuoi();
    cout <<"\n --- THONG TIN NGUOI CO TUOI CAO NHAT --- "<<endl;
    for(int i=1; i<n; i++)
    {
        if(max < a[i].gettuoi())
        {
            max = a[i].gettuoi();
            chisomax = i;
        }
    }
    a[chisomax].Xuat();
    cout <<"\n --- THONG TIN NGUOI CO TUOI NHO NHAT --- "<<endl;
    for(int i=1; i<n; i++)
    {
        if(min > a[i].gettuoi())
        {
            min = a[i].gettuoi();
            chisomin = i;
        }
    }
    a[chisomin].Xuat();
    return 0;

}