#include <iostream>
#include <iomanip>
using namespace std;

struct HocPhan{
	float diem;
	int soTinChi;
};

float tinhDiem(HocPhan ds[], int n){
	float tongDiem = 0;
	int tongTinChi = 0;
	
	for(int i = 0; i < n; i++){
		tongDiem += ds[i].diem * ds[i].soTinChi;
		tongTinChi += ds[i].soTinChi;
	}
	
	return tongDiem / tongTinChi;
}

int main(){
	HocPhan ds[10];
	int n;
	
	cout <<"Nhap so hoc phan: ";
	cin >> n;
	
	for(int i = 0; i < n; i++){
        cout << "Nhap diem hoc phan " << i + 1 << ": ";
        cin >> ds[i].diem;

        cout << "Nhap so tin chi hoc phan " << i + 1 << ": ";
        cin >> ds[i].soTinChi;
        
        cout << endl;
    }
	
	cout <<"\n----------------------\n";
	float dtb = tinhDiem(ds, n);
	cout << "Diem trung binh: " << fixed << setprecision(2) << dtb << endl;

    return 0;
}
