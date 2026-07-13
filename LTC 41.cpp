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
	printf("\nGia tri cua mang la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}	
}

void xuatmangnguoc(int a[], int n){
	printf("\nGia tri cua mang dao la: ");
	for(int i = n - 1; i >= 0; i--){
		printf("%d ", a[i]);
	}	
}

void daonguocmang(int a[], int n){
	for(int i = 0; i < n/2; i++){
		int tam = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = tam;
	}
}

int main(){
	int a[10];
	int n;
	
	nhapmang(a, n);
	xuatmang(a, n);
	//xuatmangnguoc(a, n);
	daonguocmang(a, n);
	xuatmang(a, n);
}
