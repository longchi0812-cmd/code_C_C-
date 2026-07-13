#include <stdio.h>

void nhapmang(int a[], int &n, int b[]){
	do{
		printf("Nhap phan tu mang(n<=10): ");
		scanf("%d", &n);
	}while(n > 10);
	for(int i = 0; i< n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i< n; i++){
		printf("b[%d] = ", i);
		scanf("%d", &b[i]);
	}
	
}

void mangc(int c[], int n, int a[], int b[]){
	for(int i = 0 ; i < n; i ++){
		c[i] = a[i] + b[i];
	}
}

void xuatmang(int a[], int n){
	//printf("Noi dung cua mang la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(){
	int a[10], n;
	int b[10], c[10];
	
	nhapmang(a, n, b);
	
	mangc(c, n, a, b);
	
	printf("\nMang a: ");
	xuatmang(a, n);
	
	printf("Mang b: ");
	xuatmang(b, n);
	
	printf("Mang c = a + b: ");
	xuatmang(c, n);

}
