#include<stdio.h>
#include<string.h>
#include<ctype.h>

int dem_space(char s[]){
	int dem=0;
	for(int i=0; i<strlen(s); i++){
		if(isspace(s[i]))
			dem++;
	}
	return dem;
}

int main(){
	char s[50];
	
	printf("Nhap xau ky tu: ");
	gets(s);
	
//	fgets(s, sizeof(s), stdin);
//	s[strcspn(s, "\n")] = '\0'; // xóa ký t? newline n?u có

	
	int dem=dem_space(s);
	printf("So khoang trang trong xau la: %d", dem);
}
