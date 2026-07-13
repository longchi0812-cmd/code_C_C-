#include<stdio.h>
int main(){
	int x1, x2, x3, x4, min, max;
	printf("Nhap x1: ");
	scanf("%d", &x1);
	printf("Nhap x2: ");
	scanf("%d", &x2);
	printf("Nhap x3: ");
	scanf("%d", &x3);
	printf("Nhap x4: ");
	scanf("%d", &x4);
	min = x1;
	if (min > x2)
		min = x2;
	if (min > x3)
		min = x3;
	if (min > x4)
		min = x4;
	printf("min: %d \n", min);
	
	max = x1;
	if (max < x2)
		max = x2;
	if (max < x3)
		max = x3;
	if (max < x4)
		max = x4;
	printf("max: %d \n", max);
}
