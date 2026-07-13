#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

int Min(int a[], int n){
	int min = a[0];
	for(int i = 1; i<n; i++){
		if(min > a[i])
			min = a[i];	
	}
	return min;
}

int Max(int a[], int n){
	int max = a[0];
	for(int i = 1; i<n; i++){
		if(max < a[i])
			max = a[i];	
	}
	return max;
}


int main(){
	int  a[100], n;
	
	nhapmang(a, n);
	
	printf("\nmax = %d", Max(a, n));
	
	printf("\nmin = %d", Min(a, n));
}
