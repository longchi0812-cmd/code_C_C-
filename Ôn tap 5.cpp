#include <stdio.h>
int main() {
	float thunhap, tienchiuthue, thueTNCN;
	int n;
	
	printf("Nhap thu nhap 1 thang: ");
	scanf("%f", &thunhap);
	printf("Nhap so nguoi phu thuoc: ");
	scanf("%d", &n);

	tienchiuthue=thunhap-(9000000+n*3600000);
	if(tienchiuthue>0)
		thueTNCN=5000000*5/100+(tienchiuthue-5000000)*10/100;
		printf("Thue thu nhap ca nhan: %.0f VND", thueTNCN);
}
