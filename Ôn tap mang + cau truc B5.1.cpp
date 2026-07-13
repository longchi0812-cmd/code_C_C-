#include <stdio.h>

struct MATHANG{
	char mahang[10];
	char tenhang[50];
	int soluong;
	float dongia;
	char donvitinh[10]; 
	float thanhtien;
};

void nhap(struct MATHANG &m){
	printf("Nhap ma mat hang: ");
	scanf("\n");
	gets(m.mahang);
	
	printf("Nhap ten hang: ");
	scanf("\n");
	gets(m.tenhang);
	
	printf("Nhap so luong: ");
	scanf("\n");
	scanf("%d", &m.soluong);
	
	printf("Nhap don gia: ");
	scanf("\n");
	scanf("%f", &m.dongia);
	
	printf("Nhap doi vi tinh: ");
	scanf("\n");
	gets(m.donvitinh);
	
	m.thanhtien = m.dongia * m.soluong;
}

void in(struct MATHANG m){
	if(m.soluong > 20){
		printf("Ma hang: %s\n", m.mahang);
		printf("Ten hang: %s\n", m.tenhang);
		printf("So luong: %d\n", m.soluong);
		printf("Don gia: %.2f\n", m.dongia);
		printf("Don vi tinh: %s\n", m.donvitinh);
		printf("Thanh tien: %.2f\n", m.thanhtien);
	}
}

void ghifile(struct MATHANG m, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f == NULL){
		return;	
	}
	fprintf(f, "Ma hang: %s\n", m.mahang);
	fprintf(f, "Ten hang: %s\n", m.tenhang);
	fprintf(f, "So luong: %d\n", m.soluong);
	fprintf(f, "Don gia: %.2f\n", m.dongia);
	fprintf(f, "Don vi tinh: %s\n", m.donvitinh);
	fprintf(f, "Thanh tien: %.2f\n", m.thanhtien);
	
	fclose(f);
}

void docfile(struct MATHANG m, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f == NULL){
		return;
	}
	fscanf(f, "%s\n", &m.mahang);
	fscanf(f, "%s\n", &m.tenhang);
	fscanf(f, "%d\n", &m.soluong);
	fscanf(f, "%.2f\n", &m.dongia);
	fscanf(f, "%s\n", &m.donvitinh);
	fscanf(f, "%.2f\n", &m.thanhtien);
	
	fclose(f);
}

int main(){
	struct MATHANG m1, m2;
	printf("\nNhap mat hang thu nhat: \n");
	nhap(m1);
	printf("\n-----\n");
	printf("\nNhap mat hang thu hai: \n");
	nhap(m2);
	printf("\n-----\n");
	ghifile(m1, "mahang1.txt"); 
	docfile(m1, "mahang1.txt");
	in(m1);
	printf("\n-----\n");
	ghifile(m2, "mahang2.txt");
	docfile(m2, "mahang2.txt");
	in(m2);
}
