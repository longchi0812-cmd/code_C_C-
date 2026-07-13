#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("\nNhap so luong phan tu mang: ");
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

int timmax(int a[], int n){
	int max = a[0];
	for(int i = 0; i < n; i++){
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

void inMangConKhongGiam(int a[], int n){
	int b[10];
	for(int i = 0; i < n; i++){
		b[i] = 1;
	}
	
	for(int i = n - 1; i > 0; i--){
		if(a[i] >= a[i - 1]){
			b[i-1] = b[i]+1;
		}
	}
	printf("\nMang b: ");
	xuatmang(b, n);
	
	int soluong = timmax(b, n);
	for(int i = 0; i < n; i++){
		if(b[i] == soluong){
			printf("\nMang khong giam dai nhat: ");
			for(int j = i; j < soluong + i; j++)
				printf("%d ", a[j]);
		}
	}
}

int main(){
	int a[10], n;
	
	nhapmang(a, n);
	xuatmang(a, n);
	
	inMangConKhongGiam(a, n);
}
