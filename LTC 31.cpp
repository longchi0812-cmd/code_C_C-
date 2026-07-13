#include "stdio.h"

void swap_thamtri(int a, int b){
	int tam = a;
	a = b;
	b = tam;
}

void swap_thamchieu(int &a, int &b){
	int tam = a;
	a = b;
	b = tam;
}


int main(){
	int a, b;
	printf("Nhap vao 2 so a, b: ");
	scanf("%d%d", &a, &b);
	
	printf("\nGia tri ban dau: a=%d va b=%d", a, b);
	swap_thamtri(a, b);
	printf("\nHoan doi - truyen tham tri: a=%d va b=%d", a, b);
	swap_thamchieu(a, b);
	printf("\nHoan doi - truyen tham chieu: a=%d va b=%d", a, b);
}
