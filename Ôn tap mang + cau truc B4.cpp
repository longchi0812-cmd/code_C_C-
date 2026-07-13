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

int kiemtradoixung(int a[], int n){
	for(int i = 0 ; i < n / 2; i++){
		if(a[i] != a[n - 1 - i])
			return 0;
	}
	return 1;
}

int main(){
	int a[10], n;
	nhapmang(a, n);
	
	if(kiemtradoixung(a, n))
		printf("Mang doi xung");
	else
		printf("Mang khong doi xung");
		
	xuatmang(a, n);
}
