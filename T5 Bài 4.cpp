#include <stdio.h>
#include <math.h>

void nhapmang(int a[], int &n){
	printf("Nhap so phan tu mang: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

void hoanvi(int &a, int &b){
	int tam = a;
	a = b;
	b = tam;
}

void sap_xep_giam(int a[], int n){
	for(int i = 0; i < n- 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] > a[i])
				hoanvi(a[i], a[j]);
		}
	}
}

void tach_mang(int a[], int n, int b[], int &n1, int c[], int &n2){
	n1 = n2 = 0;
	for(int i = 0 ; i < n; i++){
		if(a[i] >= 0){
			b[n1++] = a[i];
		}else{
			c[n2++] = a[i];
		}
	}
}

void themvitrik(int a[], int &n, int x, int k){
	n++;
	for(int i = n - 1; i > k; i--){
		a[i] = a[i - 1];
	}
	a[k] = x;
}

int La_snt(int n){
	if(n < 2)
		return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

void chem_so_0(int a[], int &n){
	for(int i = 0; i< n; i++){
		if(La_snt(a[i]))
			themvitrik(a, n, 0, i+1);
	}
}

void xoa(int a[], int &n, int vi_tri){
	for(int i = vi_tri; i < n - 1; i++){
		a[i] = a[i+1];
	}
	n--;
}

void xoa_snt(int a[], int &n){
	for(int i = 0; i < n; i++){
		if(La_snt(a[i])){
			xoa(a, n, i);
			i--;
		}
	}
}

int main(){
	int a[10], n;
	int b[10], n1;
	int c[10], n2;
	
	nhapmang(a, n);
	
	printf("Mang giam dan: ");
	sap_xep_giam(a, n);
	xuatmang(a, n);
	
	tach_mang(a, n, b, n1, c, n2);
	printf("\nMang b: ");
	xuatmang(b, n1);
	printf("\nMang c: ");
	xuatmang(c, n2);
	
	themvitrik(a, n, 99, 2);
	printf("\nMang sau khi chen: ");
	xuatmang(a, n);
	
	chem_so_0(a, n);
	printf("\nMang sau khi chen: ");
	xuatmang(a, n);
	
	xoa_snt(a, n);
	printf("\nMang sau khi xoa: ");
	xuatmang(a, n);
}
