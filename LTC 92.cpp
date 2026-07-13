#include <stdio.h>
#include <stdlib.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void xuatmang(int a[], int n){
	printf("\nNoi dung cua mang la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}
void xuatfile(int a[], int n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f==NULL){
		printf("\n Loi mo file");
		return;
	}
	fprintf(f, "%d\n", n);
	for(int i=0; i<n; i++){
		fprintf(f, "%d\n", a[i]);
	}
	fclose(f);
}
void xuatfile2(int a[], int n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f==NULL){
		printf("\nLoi mo file");
		return;
	}
	for(int i = 0; i < n; i++){
		fprintf(f, "%d\n", a[i]);
	}
	fclose(f);
}
// xuat file 2 la xuat khong có n
// nhap file 2 cung tuong tu nhu vay
void nhapfile(int a[], int &n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f==NULL){
		printf("\n Loi mo file");
		return;
	}
	fscanf(f, "%d", &n);
	printf("%d",n);
	for(int i=0; i<n; i++){
		fscanf(f, "%d", &a[i]);
	}
	fclose(f);
}
void nhapfile2(int a[], int &n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f==NULL){
		printf("\n Loi mo file");
		return;
	}
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%d", &a[i]);
		i++;
	}
	n = i;
	
	fclose(f);
}
int main(){
	int a[10], n;
	
//	nhapmang(a, n);
//	xuatfile(a, n,"Bai_92.out");
//	xuatfile2(a, n,"Bai_92_2.out");
//	xuatmang(a, n);
	nhapfile(a, n, "Bai_92.out");
	xuatmang(a, n);
//	nhapfile2(a, n, "Bai_92_2.out");
//	xuatmang(a, n);
}
