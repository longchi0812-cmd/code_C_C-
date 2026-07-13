#include<stdio.h>
int main(){
	int soluong;
	float thanhtien, dongia, thue;
	printf("\n Nhap so luong san pham: ");
	scanf("%d", &soluong);
	printf("\n Nhap don gia san pham: ");
	scanf("%f", &dongia);
	thanhtien = soluong * dongia;
	thue = thanhtien * 10/100;
	printf("\n Thanh tien: %.0f", thanhtien);
	printf("\n Thue gia tri gia tang: %.0f", thue);
}
