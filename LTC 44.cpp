#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

void xoamangtaivitri(int a[], int &n, int vi_tri){
	for(int i = vi_tri; i < n - 1; i++){
		a[i] = a[i+1];
	}
	n--;
}

void xoamangtheogiatri(int a[], int &n){
	int gt;
	printf("\nNhap gia tri can xoa: ");
	scanf("%d", &gt);
	
	for(int i = 0; i < n; i++){
		if(a[i] == gt){
			xoamangtaivitri(a, n, i);
			i--;
		}
	}
}

int main(){
	int a[10], n;
	
	nhapmang(a, n);
	xuatmang(a, n);
	printf("\n");
	xoamangtheogiatri(a, n);
	xuatmang(a, n);
	
}
