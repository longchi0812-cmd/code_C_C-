#include <stdio.h>
#include <math.h>
void nhapmang(int a[], int &n, int m, int d){
	do{
		printf("Nhap phan tu mang(n<=10): ");
		scanf("%d", &n);
	}while(n > 10);
	a[0] = m;
	for(int i = 1; i< n; i++){
		a[i] = a[i - 1] + d;
	}
}
int xuatmang(int a[], int n){
	int s = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 3 == 0)
			s+=a[i];
	}
	return s;
}

void ghifile(int a[], int n, const char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f == NULL){
		printf("Loi tao mo file");
		return;
	}
	
	fprintf(f, "%d\n", n);
	for(int i = 0; i < n; i++){
		fprintf(f, "%d ", a[i]);
	}
	
	fclose(f);
}

void docfile(int a[], int &n, const char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f == NULL){
		printf("Loi mo file");
		return;
	}
	
	fscanf(f, "%d\n", &n);
	for(int i = 0; i < n; i++){
		fscanf(f, "%d ", &a[i]);
	}
	
	fclose(f);
}

int main(){
	int a[10], n;
	int m, d;
	//char tenfile[50];
	printf("Nhap so hang dau m: ");
	scanf("%d", &m);
	
	printf("Nhap cong sai d: ");
	scanf("%d", &d);
	
	nhapmang(a, n, m, d);
	ghifile(a, n, "songuyen.txt");	
	docfile(a, n, "songuyen.txt");
	printf("Tong cac so chia het cho 3 la: %d", xuatmang(a, n));
}
