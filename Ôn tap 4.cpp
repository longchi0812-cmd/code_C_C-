#include <stdio.h>
int main() {
	int a, b;
	float S, C;
	
	printf("Nhap do dai canh a: ");
	scanf("%d", &a);
	printf("Nhap do dai canh b: ");
	scanf("%d", &b);
	
	if(a==b) {
		S=a*a;
		printf("Dien tich cua hinh vuong la: %.2f", S);
	}
	else {
		C=(a+b)*2;
		printf("Chu vi hinh chu nhat la: %.2f", C);
	}
}

