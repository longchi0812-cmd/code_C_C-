#include<stdio.h>
#include<string.h>

int dem_ktvt_5(char s[]){
	if(strlen(s) < 5)
    	return -1; // báo l?i n?u không có ký t? th? 5
    	
	char c = s[4];
	int dem = 0;
	for(int i = 0; i < strlen(s); i++){
		if(s[i] == c)
			dem++;
	}
	return dem;
}

int main(){
	char s[50];
	
	printf("Nhap xau ky tu: ");
	gets(s);
	
	int dem_kt=dem_ktvt_5(s);
	if(dem_kt == -1)
        printf("Chuoi khong co ky tu thu 5.\n");
    else
        printf("So lan ky tu thu 5 xuat hien la: %d\n", dem_kt);
}
