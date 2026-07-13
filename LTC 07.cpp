#include<stdio.h>
int main(){
	int a, b;
	printf("Nhap vao a = ");
	scanf("%d", &a);
	printf("Nhap vao b = ");
	scanf("%d", &b);
	
	printf("\n %d == %d la %d", a, b, a==b);
	printf("\n %d > %d la %d", a, b, a>b);
	printf("\n %d < %d la %d", a, b, a<b);
	printf("\n %d <= %d la %d", a, b, a<=b);
	printf("\n %d >= %d la %d", a, b, a>=b);
	printf("\n %d != %d la %d", a, b, a!=b);
}
