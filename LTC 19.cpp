#include<stdio.h>
#include<math.h>
int main(){
	float xa, ya, xb, xc, yb, yc;
	float AB, BC, CA;
	float chuvi, dientich, p;
	
	printf("\nNhap vao toan do dinh A: ");
	scanf("%f%f", &xa, &ya);
	printf("\nNhap vao toan do dinh B: ");
	scanf("%f%f", &xb, &yb);
	printf("\nNhap vao toan do dinh C: ");
	scanf("%f%f", &xc, &yc);
	
	// Tinh do dai cac canh cua tam giac
	AB = sqrt(pow(xa-xb, 2) + pow(ya-yb, 2));
	BC = sqrt(pow(xb-xc, 2) + pow(yb-yc, 2));
	CA = sqrt(pow(xc-xa, 2) + pow(yc-ya, 2));
	
	if(AB+BC>CA && AB+CA>BC && BC+CA>AB){
		printf("ABC tao thanh tam giac");
		
		if(AB ==  BC || AB == CA || BC == CA)
			printf("ABC la tam giac can");
		else
			printf("ABC khong la tam giac can");
			
		chuvi = AB + BC + CA;
		printf("\nChu vi tam giac ABC la: %.2f", chuvi);
	
		p = chuvi/2;
		dientich = sqrt(p*(p-AB)*(p-BC)*(p-CA));
		printf("\nDien tich tam giac ABC la: %.2f", dientich);
		
	}else 
		printf("ABC khong tao thang tam giac");		
}
