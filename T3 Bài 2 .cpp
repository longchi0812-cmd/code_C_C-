#include <stdio.h>
int main() {
	int a, b;
	printf("Nhap gia tri a: ");
	scanf("%d", &a);
	printf("Nhap gia tri b: ");
	scanf("%d", &b);
	for (int i = a; i <= b; i++)
		if (i % 3 == 0)
			printf(" %d", i);
}
