#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	printf("Gia tri cua mang la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

int timkiem(int a[], int n, int tk){
	int kq = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == tk){
			kq = 1;
			return 1;
		}
	}
	return kq;
}

void thuchientk(int a[], int n){
	int tk;
	printf("Nhap vao gia tri can tim: ");
	scanf("%d", &tk);
	int kq = timkiem(a, n, tk);
	if(kq == 1)
		printf("\nTim thay");
	else
		printf("\nKhong tim thay");
}

int main(){
	int a[10], n;
	
	nhapmang(a, n);
	xuatmang(a, n);
	
	thuchientk(a, n);
	
}
