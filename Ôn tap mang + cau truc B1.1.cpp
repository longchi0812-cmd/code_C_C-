#include <stdio.h>
struct SinhVien{
	char ho_ten[50];
	float diem_ltcb;
	float diem_ctdl;
};

void nhapsinhvien(struct SinhVien &s){
	
	printf("\nNhap ho ten: ");
	scanf("\n"); // scanf de bo enter
	gets(s.ho_ten);
	
//	fflush(stdin); // Xoá b? d?m tru?c khi nh?p chu?i
//	fgets(s.ho_ten, sizeof(s.ho_ten), stdin);
//	// Xoá kí t? '\n' do fgets t? d?ng thêm vào
//	size_t len = strlen(s.ho_ten);
//	if (len > 0 && s.ho_ten[len - 1] == '\n') {
//    s.ho_ten[len - 1] = '\0';
//}

	
	printf("Nhap diem ltcb: ");
	scanf("%f", &s.diem_ltcb);
	printf("Nhap diem ctdl: "); 
	scanf("%f", &s.diem_ctdl);	
}

float diemtrungbinh(struct SinhVien s){
	float diem = 0;
	diem = s.diem_ltcb + s.diem_ctdl;
	diem = diem / 2;
	
	return diem;
}

int check(struct SinhVien s){
	if(diemtrungbinh(s) >=9 && (s.diem_ltcb >= 9 || s.diem_ctdl >= 9) && (s.diem_ltcb >= 7 && s.diem_ctdl >=7)){
		return 1;
	}
	return 0;
}

void in(struct SinhVien s){
	printf("ho ten: %s  diem ltcb: %.2f   diem ctdl: %.2f    diemtb: %.2f", s.ho_ten, s.diem_ltcb, s.diem_ctdl, diemtrungbinh(s));
}
int main(){
	struct SinhVien s1, s2;
	
	printf("\nNhap sinh vien thu nhat.");
	nhapsinhvien(s1);
	
	printf("-----");
	
	printf("\nNhap sinh vien thu hai.");
	nhapsinhvien(s2);
	printf("-----");
	printf("\nxep loai xuat sac: ");	printf("\n");
	if(check(s1) == 1){
		in(s1);
	}
	printf("\n");
	if(check(s2) == 1){
		in(s2);
	}
	printf("\n-----");
	printf("\nSinh vien co diem cao nhat la: ");
	printf("\n");
	if(diemtrungbinh(s1) > diemtrungbinh(s2)){
		in(s1);
	}else{
		in(s2);
	}
	
}
