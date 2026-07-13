#include <stdio.h>

void nhapmang(int x[], int &n){
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("x[%d] = ", i);
		scanf("%d", &x[i]);
	}
}

float trungBinhCong(int x[], int n){
	int tong = 0;
	for(int i=0; i<n; i++){
		tong+=x[i];
	}
	return (float)tong/n;
}

float trungBinhCongSoDuong(int x[], int n){
	int tong = 0;
	int soLuongSoDuong=0;
	for(int i=0; i<n; i++){
		if(x[i]>=0){
			tong+=x[i];
			soLuongSoDuong++;
		}
	}
	return soLuongSoDuong>0?(float)tong/soLuongSoDuong:-1;
}
int main(){
	int x[100];
	int n;

	nhapmang(x, n);
	
	printf("\nTrung binh cong: %.2f", trungBinhCong(x, n));
	
	float tbcsd = trungBinhCongSoDuong(x, n);
	if(tbcsd>0){
		printf("\nTrung binh cong so duong: %.2f", tbcsd);
	}else{
		printf("\nMang khong co so duong!");
	}
	
}
