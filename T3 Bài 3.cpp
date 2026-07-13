#include <stdio.h>
int main() {
	int n, s1, s2;
	printf("\n Nhap so nguyen n: ");
	scanf("%d", &n);
	s1 = 0;
	for(int i = 0; i <= n; i++)
		if(i % 2 != 0)
			s1 = s1 + i;
			printf("\n Tong cac so le = %d", s1);
	s2 = 0;
	for(int i = 0; i <= n; i++)
		if(i % 2 == 0)
			s2 = s2 + i;
			printf("\n Tong cac so chan = %d", s2);
}
