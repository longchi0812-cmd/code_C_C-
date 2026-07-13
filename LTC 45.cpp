#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	printf("\nNoi dung cua mang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

void themvitridau(int a[], int &n, int x){
	n++;
	for(int i = n - 1; i > 0; i--){
		a[i] = a[i - 1];
	}
	a[0] = x;
}

void themvitricuoi(int a[], int &n, int x){
	a[n] = x;
	n++;
}

// nhap n = 3
// nhap x = 99, k = 2
// cac so con lai nhap theo thu tu
void chenvitrik(int a[], int &n, int x, int k){
	n++; // n = 4
	for(int  i = n - 1; i > k; i--){
		a[i] = a[i - 1];
	}
	a[k] = x; 
	// 0 1 2 3
}	// 1 2 3 
	// i = 4 - 1 = 3 , tmdk, i = 2;
	// a[3] = a[2]
	// 0 1 2 3
	// 1 2   3
	// 1 2 99 3

int main(){
	int a[10], n;
	int x;
	
	printf("Nhap x: ");
	scanf("%d", &x);
	
	nhapmang(a, n);
	
	chenvitrik(a, n, x, 2);
	printf("\n");
	xuatmang(a, n);
	
	themvitridau(a, n, x);
	printf("\n");
	xuatmang(a, n);
	
	themvitricuoi(a, n, x);
	printf("\n");
	xuatmang(a, n);
}
