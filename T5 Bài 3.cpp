#include <stdio.h>
#include <math.h>

void nhapmang(int a[], int &n){
	do{
		printf("Nhap so phan tu mang: ");
		scanf("%d", &n);	
	} 
	while(n < 3 || n > 10);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

int mang_toan_chan(int a[], int n){
	for(int i = 0; i < n; i++){
		if(a[i] % 2 != 0)
			return 0;
	}
	return 1;
}

int la_snt(int n){
	if(n < 2)
		return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int mang_toan_SNT(int a[], int n){
	for(int i = 0; i < n; i++){
		if(!la_snt(a[i]))
			return 0;
	}
	return 1;
}

int mang_tang_dan(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		if(a[i] > a[i+1])
			return 0;
	}
	return 1;
}

int mang_cap_so_cong(int a[], int n){
	int d = 0;
	d = a[1] - a[0];
	for(int i = 0; i < n - 1; i++){
		if(a[i + 1] - a[i] != d)
			return 0;
	}
	return 1;
}

int main(){
	int a[10], n;
	
	nhapmang(a, n);
	
	if(mang_toan_chan(a, n) != 0)
		printf("\nMang toan chan");
	else 
		printf("\nMang khong toan chan.");
		
	if(mang_toan_SNT(a, n) != 0)
		printf("\nMang toan SNT");
	else
		printf("\nMang khong toan SNT");
		
	if(mang_tang_dan(a, n) != 0)
		printf("\nMang tang dan.");
	else 
		printf("\nMang khong tang dan.");
		
	if(mang_cap_so_cong(a, n) != 0)
		printf("\nMang la cap so cong.");
	else
		printf("\nMang khong phai là cap so cong.");
}
