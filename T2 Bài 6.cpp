#include <stdio.h>
int main(){
	int a, b, c;
	/*int ag, bg, cg;*/
	printf("Nhap do dai canh a: ");
	scanf("%d", &a);
	printf("Nhap do dai canh b: ");
	scanf("%d", &b);
	printf("Nhap do dai canh c: ");
	scanf("%d", &c);
	if (a + b <= c || a + c <= b || b + c <= a)
        printf("Ba canh khong tao thanh tam giac");
    else if (a == b && b == c)
		printf("Tam giac deu");
	else if (a != b && b != c && c != a)
		printf("Tam giac thuong");
	else if (a = b && b != c)
		printf("Tam giac can");
}// chua biet cach tinh goc
