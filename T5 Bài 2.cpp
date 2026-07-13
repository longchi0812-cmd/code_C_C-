#include<stdio.h>
#include <math.h>

void nhapmang(float a[], int &n){
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
	
		printf("\n a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}
int tim_vi_tri(float a[], int n, float x){
	int vt = -1;
	for(int i = 0; i < n; i++){
		if(a[i] == x)
			vt = i;
	} 
	return vt;
}

int la_snt(float n){
	if(n < 2)
		return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if((int)n % i == 0)
			return 0;
	}
	return 1;
}

int vt_snt_dt(float a[], int n){
	for(int i = 0; i < n; i++){
		if(la_snt(a[i]))
			return i;
	}
	return -1;
}

int min(float a[], int n){
	int min = a[0];
	for(int i = 1; i < n; i++){
		if(min > a[i])
			min = a[i];
	}
	return min;
}

int max(float a[], int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(max < a[i])
			max = a[i];
	}
	return max;
}

int min_duong(float a[], int n){
	int min = max(a, n);
	for(int i = 0; i < n; i++){
		if(a[i] > 0 && min > a[i])
			min = a[i];
	}
	return min;
} 

int main(){
	int n;
	float a[10], x;
	
	nhapmang(a, n);
	printf("\nNhap x can tim: ");
    scanf("%f", &x);
	//
    int vt_cuoi = tim_vi_tri(a, n, x);
    if (vt_cuoi != -1)
        printf("\nVi tri cuoi cung cua x la: %d", vt_cuoi);
    else
        printf("\nKhong tim thay x trong mang.");
    //    
    if(vt_snt_dt(a, n) != -1)
    	printf("\nVi tri cua so nguyen to dau tien la: %d", vt_snt_dt(a, n));
    else
    	printf("\nKhong co so nguyen to trong mang.");
    //
    printf("\nSo nho nhat trong mang la: %d", min(a, n));
    //
    if(min_duong(a, n) > 0)
    	printf("\nSo duong nho nhat trong mang la: %d", min_duong(a, n));
    else
    	printf("\nKhong co so duong trong mang.");
}
