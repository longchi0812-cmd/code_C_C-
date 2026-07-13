#include<stdio.h>
#include<math.h>
int main(){
	float x, bt;
	printf("Nhap so thuc x: ");
	scanf("%f", &x);
	bt = 1+9*x - 2*sin(x)+x*x- exp(x);
	printf("gia tri bieu thuc la: %.2f", bt);
} 

