#include <stdio.h>
#include <string.h>
int dem_lan_xuat_hien(char s[], char c){
	int dem =0;
	for(int i = 0 ; s[i]!='\0'; i++){
		if(s[i] == c){
			dem++;
			s[i]= '5';
		}
	}
	return dem;
}

int tim_vi_tri_dau_tien(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i+1;
        }
    }
    return -1;
}

int main(){
	char s[100];
	char c;

	printf("Nhap xau: ");
	gets(s);
	
	printf("Nhap ki tu: ");
	scanf("%c", &c);
	
	//int vi_tri = tim_vi_tri_dau_tien(s, c);
		printf("Vi tri dau tien cua '%c': %d\n", c, tim_vi_tri_dau_tien(s, c));
	//int dem = dem_lan_xuat_hien(s, c);
		printf("So lan xuat hien cua ki tu %c la: %d\n", c, dem_lan_xuat_hien(s, c));
		printf("Chuoi sau khi thay: %s\n", s);
}

