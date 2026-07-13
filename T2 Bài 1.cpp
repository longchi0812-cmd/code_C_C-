#include <stdio.h>
main(){
	int n;
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	if (n < 0) printf("n la so am");
	if (n > 0) printf("n la so duong");
	if (n == 0) printf("n la bang 0");
}
