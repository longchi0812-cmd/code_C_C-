#include<stdio.h>
int main(){
	// khai bao bien
	int a, b;
	int min, max;
	//nhap du lieu 
	printf("nhap vao a = ");
	scanf("%d", &a);
	printf("nhap vao b = ");
	scanf("%d", &b);
	
	// xu ly
	min = (a<b)?a:b;
	max = (a>b)?a:b;
	// xuat du lieu
	printf("\n max = %d", max);
	printf("\n min = %d", min);
	
}
