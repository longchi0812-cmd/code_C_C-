#include<stdio.h>
int gia_tri_nn(int a, int b, int c, int d){
	int min=a;
	if(min>b)
		min=b;
	if(min>c)
		min=c;
	if(min>d)
		min=d;
	return min;
}
int main(){
	int m, n, o, p, nho_nhat;
	
	printf("Nhap 4 so nguyen: ");
	scanf("%d %d %d %d", &m, &n, &o, &p);
	
	nho_nhat=gia_tri_nn(m, n, o, p);
	printf("Gia tri nho nhat la: %d", nho_nhat);
	
	return 0;
}
