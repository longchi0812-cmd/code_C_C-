#include<stdio.h>
int main(){
	int c;
	
	do {
		printf("\n------");
		printf("\nMENU:");
		printf("\nNhap vao ky tu 0 de thoat");
		printf("\nNhap vao so bat ky khac 0 de tiep tuc");
		scanf("%d", &c);
	}
	while(c!=0);
}
