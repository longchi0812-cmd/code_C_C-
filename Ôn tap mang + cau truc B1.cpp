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
	printf("\nCac so chia het cho 3 va 5 la: ");
	for(int i = 0; i < n; i++){
		if(a[i] % 3 == 0 && a[i] % 5 == 0)
			printf("%d ", a[i]);
	}
	printf("\n");
}

int dem(int a[], int n, int x){
	int dem = 0;
	for(int i =0; i<n; i++){
		if(a[i] == x)
			dem++;
	}
	return dem;
}

int La_scp(int n){
	if(n < 0)
		return 0;
	int can = sqrt(n);
	if(can * can == n)
		return 1;
	else
		return 0;
}

int dem_scp(int a[], int n){
	int dem_scp = 0;
	for(int i = 0; i < n; i++){
		if(La_scp(a[i]))
			dem_scp++;			
	}
	return dem_scp;
}
void ghifile(int a[], int n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f == NULL){
		printf("\nLoi tao mo file");
		return;
	}
	fprintf(f, "%d\n", n);
	for(int i = 0; i < n; i++){
		fprintf(f, "%d ", a[i]);
	}
	fclose(f);
}

void docfile(int a[], int &n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f == NULL){
		printf("\nLoi mo file");
		return;
	}
	fscanf(f, "%d", &n);
	printf("\n%d", n);
	for(int i = 0; i < n; i++){
		fscanf(f, "%d", &a[i]);
	}
	fclose(f);
}

int main(){
	int a[10], n;
	int x;
	
	nhapmang(a, n);
	
	ghifile(a, n, "songuyen.txt");
	docfile(a, n, "songuyen.txt");
	
	xuatmang(a, n);
	
	printf("\nNhap x: ");
	scanf("%d", &x);
	
	if(dem(a, n, x) > 0)
		printf("\nSo lan xuat hien cua %d la: %d", x, dem(a, n, x));
	else
		printf("\nx khong xuat hien trong mang");
	
	if(dem_scp(a, n) > 0)
		printf("\nCo %d so chinh phuong trong mang", dem_scp(a, n));
	else
		printf("\nKhong co so chinh phuong trong mang");	
}
