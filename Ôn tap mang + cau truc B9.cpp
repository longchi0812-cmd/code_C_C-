#include <stdio.h>
#include <stdlib.h>
void nhapmang(int a[], int &n){
	printf("Nhap phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 0; i< n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void xuatmang(int a[], int n){
	printf("\nNoi dung cua mang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
int tim_so(int a[], int n, int x){
	int m = abs(a[0] - x);
	int vt = a[0];
	for(int i = 1; i < n; i++){
		if(m > abs(a[i] - x)){
			m = abs(a[i] - x);
			vt = a[i];
		}
	}
	return vt;
}

int main(){
	int a[10], n, x;
	nhapmang(a, n);
	printf("Nhap x: ");
	scanf("%d", &x);
	
	printf("So gan x nhat la: %d", tim_so(a, n, x));
	xuatmang(a, n);
}
