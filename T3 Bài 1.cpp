#include<stdio.h>
int main()
{
	int a, b, T;
	printf("Nhap gia tri a: ");
		scanf("%d", &a);
	printf("Nhap gia tri b: ");
		scanf("%d", &b);
		if (a > b ) 
			printf("Khong co ket qua nhap sai");
		else if (a < b)
		{
			for (int i = a; i <=b; i++)
			T = T + i;
		}
			printf("\nTong cac so tu a den b: %d", T);
}
