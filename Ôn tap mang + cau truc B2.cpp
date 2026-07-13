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
int kiemtra(int a[], int n){
	for(int i = 1; i<n; i++){
		if(a[i - 1] % 2 == 0 && a[i] % 2 ==0)
			return 1;
	}
	return 0;
}

int main(){
	int a[10], n;
	nhapmang(a, n);
	
	if(kiemtra(a, n))
		printf("Mang co hai so chan canh nhau");
	else
		printf("Mang khong co hai so chan canh nhau");
		
	xuatmang(a, n);
}
