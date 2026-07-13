#include "stdio.h"
int main(){
	// Nhap so n, kiem tra n co nho hon 20, neu co thi thong bao ra man hinh
	int n;
	printf("Nhap vao n=");
	scanf("%d", &n);
	
	if(n<20){
		printf("\n So nhap vao nho hon 20");
	}
	// Nhap so n, xuat ra mna hinh na la so chan hay so le
	
	printf("Nhap vao n=");
	scanf("%d", &n);
	
	if (n%2==0){
		printf("\nSo nhap vao la so chan");
	}else{
		printf("\nSo nhap vao la so le");
	}
	// Nhap so n, xuat ra mna hinh na la so chan hay so l
	printf("Nhap vao n=");
	scanf("%d", &n);
	
	if (n%2==0){
		printf("\nSo nhap vao la so chan");
	}else if(n%2==1){
		printf("\nSo nhap vao la so le");
	}
		
}
