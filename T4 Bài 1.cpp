#include<stdio.h>
char doi_ky_tu(char c){
	if(c>=65 && c<=90)
		c=c+32;
	return c;
}

int main(){
	char n, ky_tu;
	
	printf("Nhap ky tu hoa: ");
	scanf("%c", &n);
	
	ky_tu=doi_ky_tu(n);
	
	printf("Ky tu thuong la: %c", ky_tu);
}
