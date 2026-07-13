#include <stdio.h>

struct NhanVien{
	char Manv[10];
	char Hoten[50];
	char Chuvu[50];
	int GioiTinh;
	int SoNamCong;
	float Luong;
};

void nhap(struct NhanVien &n){
	printf("Nhap Manv: ");
	scanf("\n");
	gets(n.Manv);
	
	printf("Nhap Ho ten: ");
	scanf("\n");
	gets(n.Hoten);
	
	printf("Nhap Chuc vu: ");
	scanf("\n");
	gets(n.Chuvu);
	
	printf("Nhap gioi tinh(Nam 0 / Nu 1): ");
	scanf("%d", &n.GioiTinh);
	
	printf("Nhap so nam cong tac: ");
	scanf("%d", &n.SoNamCong);
	
	printf("Nhap luong: ");
	scanf("%f", &n.Luong);
}

float tinhphucap(struct NhanVien n){
	float phucap = 0;
	if(n.SoNamCong < 5 && n.GioiTinh == 0){
		phucap = 0;
	}
	else if(n.GioiTinh == 1){
		phucap = n.Luong * 0.1;
	}	
	return phucap;
}

int main(){
	struct NhanVien n1, n2;
	
	printf("Nhap nhan vien thu nhat: \n");
	nhap(n1);
	printf("\n-----\n");
	printf("Nhap nhan vien thu hai: \n");
	nhap(n2);
	printf("\n-----\n");
	printf("\nPhu cap nhan vien (%s) = %.2f", n1.Hoten, tinhphucap(n1));
	printf("\nPhu cap nhan vien (%s) = %.2f", n2.Hoten, tinhphucap(n2));
}
