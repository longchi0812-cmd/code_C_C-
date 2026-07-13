#include<stdio.h>
#include<string.h>
#include<ctype.h>

void chuoi_chu_hoa(char s[]){
//	strupr(s);
//	puts(s);
	for(int i = 0; i<strlen(s); i++){
		if(islower(s[i]))
			s[i] = toupper(s[i]);
	}
	puts(s);
}

void chuoi_chu_thuong(char s[]){
//	strlwr(s);
//	puts(s);
	for(int i = 0; i<strlen(s); i++){
		if(isupper(s[i]))
			s[i] = tolower(s[i]);
	}
	puts(s);
}
	
void xoa_khoang_trong_thua(char s[]){
	for(int i = 0; i<strlen(s); i++){
		if((i==0 && s[i]==' ') || (s[i] ==' ' && s[i+1] ==' ') || (s[i]==' ' && s[i+1] =='\0'))
		{
			for(int k = i; k < strlen(s); k++)
				s[k]=s[k+1];
			i--;
		}
	}
}

char ky_tu_chuan(char s[]){
	if(islower(s[0]))
		s[0] = toupper(s[0]);
	for(int i = 0; i<strlen(s); i++){
		if(isspace(s[i]))
			s[i+1] = toupper(s[i+1]);
 	}
}
int main(){
	char s[100];
	
	printf("Nhap mot chuoi: ");
	gets(s);
	
	printf("Chuoi hoa: ");
		chuoi_chu_hoa(s);
		
	printf("Chuoi thuong:");
		chuoi_chu_thuong(s);
	
	ky_tu_chuan(s);
	
	xoa_khoang_trong_thua(s);
	printf("Chuoi sau khi thay doi: %s", s);
}
