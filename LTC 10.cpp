#include <stdio.h>
int main() {
	float x, a, b;
	printf("Nhap a: ");
	scanf("%f", &a);
	printf("Nhap b: ");
	scanf("%f", &b);
	x = -b/a;
	printf("Ket qua x = %.2f", x);
}
