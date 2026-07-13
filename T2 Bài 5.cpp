#include <stdio.h>
int main(){
	int x, y, ketqua;
	char toantu;
	printf("Nhap x: ");
	scanf("%d", &x);
	printf("Nhap y: ");
	scanf("%d", &y);
	printf("Nhap toan tu(+, -, *, /): ");
	scanf(" %c", &toantu);
	if (y == 0)
	printf("Khong chia duoc");	
	switch (toantu)
	{
		case '+': ketqua = x + y;
		printf("%d + %d = %d", x, y, ketqua); break;
		case '-': ketqua = x - y; 
		printf("%d - %d = %d", x, y, ketqua); break;
		case '*': ketqua = x * y;
		printf("%d * %d = %d", x, y, ketqua); break;
		case '/': ketqua = x / y;
		printf("%d / %d = %d", x, y, ketqua); break;	
	}
}
