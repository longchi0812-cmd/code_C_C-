
#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmamg(int a[], int n){
	printf("Noi dung cua mang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

void tachmang(int a[], int n, int b[], int &n1, int c[], int &n2){
	n1 = 0;
	n2 = 0;
	for(int i = 0; i<n; i++){
		if(a[i]%2==0){
			b[n1++] = a[i];
		}else{
			c[n2++] = a[i]; 
		}
	}
}

int main(){
	int a[10], b[10], c[10];
	int n, n1, n2;
	
	nhapmang(a, n);
	xuatmamg(a, n);
	
	tachmang(a, n, b, n1, c, n2);
	xuatmamg(b, n1);
	xuatmamg(c, n2);
}
