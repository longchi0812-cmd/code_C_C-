#include <stdio.h>
#include <math.h>
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
int La_snt(int n){
	if(n < 2)
		return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}
int mangtoanSNT(int a[], int n){
	for(int i = 0; i<n; i++){
		if(!La_snt(a[i]))
			return 0;
	}
	return 1;
}

int main(){
	int a[10], n;
	nhapmang(a, n);
	
	if(mangtoanSNT(a, n))
		printf("Mang chua toan SNT");
	else
		printf("Mang khong chua toan SNT");
		
	xuatmang(a, n);
}
