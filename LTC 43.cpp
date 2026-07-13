#include <stdio.h>
#include <limits.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	printf("Gia tri cua mang la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

int timMINthuhai(int a[], int n){
	int min = INT_MAX;
	int min_2 = INT_MAX;
	
	for(int i = 0; i < n; i++){
		if(a[i] < min)
			min = a[i];
	}
	
	for(int i = 0; i < n; i++){
		if(a[i] == min){
			continue;
		}else{
			if(a[i] < min_2){
				min_2 = a[i];
			}
		}
	}
	return min_2;
}

int timMAXthuhai(int a[], int n){
	int max = INT_MIN;
	int max_2 = INT_MIN;
	
	for(int i = 0; i < n; i++){
		if(a[i] > max)
			max = a[i];
	}
	
	for(int i = 0; i < n; i++){
		if(a[i] == max){
			continue;
		}else{
			if(a[i] > max_2){
				max_2 = a[i];
			}
		}
	}
	return max_2;
}

int main(){
	int a[10], n;
	
	nhapmang(a, n);
	xuatmang(a,n);
	
	printf("\nmin_2 = %d", timMINthuhai(a, n));
	
	printf("\nmax_2 = %d", timMAXthuhai(a, n));
}
