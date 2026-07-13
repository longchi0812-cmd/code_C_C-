#include <stdio.h>

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
int tim_so(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		if(a[i] > a[i - 1] && a[i] > a[i + 1])
			printf("%d ", a[i]);
	}
}

int main(){
	int a[10], n;
	nhapmang(a, n);
	printf("Cac so tim duoc la: ");
	tim_so(a, n);
	xuatmang(a, n);
}
