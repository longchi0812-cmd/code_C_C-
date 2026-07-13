#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void hoanvi(int &a, int &b){
	int tam=a;
	a = b;
	b = tam;
}

void sapxeptang(int a[], int n){
	for(int i = 0; i < n-1; i++){//chay toi phan tu ke cuoi vì khi i < n thì j = i + 1 khong thoa mãn dieu kien lap
		for(int j = i+1; j<n; j++){// vd i a[0] = 2  j a[1] = 1
			if(a[j]<a[i])// thmdk
				hoanvi(a[i], a[j]);// thuc hien ham
		}
	}
}

void sapxepgiam(int a[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j<n; j++){
			if(a[j]>a[i])
				hoanvi(a[i], a[j]);
		}
	}
}

void xuatmang(int a[], int n){
	for(int i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
}

int main(){
	int  a[100], n;
	
	nhapmang(a, n);
	
	printf("\n Mang tang dan: ");
	sapxeptang(a, n);
	xuatmang(a, n);
	
	printf("\n Mang dam dan: ");
	sapxepgiam(a, n);
	xuatmang(a, n);
}
