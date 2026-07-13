#include <stdio.h>
#include <math.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

int thoadieukien(int x){
	return (x%2==0 && x%3==0);
}

int checknt(int x){
	if(x < 1)
		return 0;
	for(int i = 2; i <= sqrt(x); i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main(){
	int  a[100], n;
	
	nhapmang(a, n);
	
	printf("Cac so chan chia het cho 3: ");
	for(int i = 0; i < n; i++){
		if(thoadieukien(a[i]))
			printf("%d ", a[i]);
	}
	
	printf("Cac so nguyen to: ");
	for(int i = 0; i < n; i++){
		if(checknt(a[i]))
			printf("%d ", a[i]);
	}
}
