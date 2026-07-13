#include <stdio.h>
#include <string.h>
#include <ctype.h>

int demchuso(char s[]){
	int dem = 0;
	for(int i = 0; i < strlen(s); i++){
		if(isdigit(s[i]))
			dem++;
	}
	return dem;
}

void ghifile(char s[], const char tenfile[]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f == NULL){
		printf("Loi tao hoac mo file!");
		return;
	}
	fprintf(f, "%s", s);	
	fclose(f);
}

void docfilevainng(char s[], const char tenfile[]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f == NULL){
		printf("Loi tao hoac mo file!");
		return;
	}
	
	fgets(s, 50, f);
	
	printf("Nguyen am co trong file: ");
	for(int i = 0; i<strlen(s); i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
			printf("%c ", s[i]);
	}
	
	fclose(f);
}

int main(){
	char s[50];
	
	printf("Nhap xau ky tu: ");
	gets(s);
	ghifile(s, "kytu.txt");
	docfilevainng(s, "kytu.txt");
	
	printf("Trong mang co %d chu so", demchuso(s));
}

