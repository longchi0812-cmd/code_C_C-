#include<stdio.h>
#include<string.h>

void doi_ky_tu(char s[], char x){
	char c = s[1];
	for(int i = 0; i < strlen(s); i++){
		if(s[i] == c)
			s[i] = x;
	}
}

int main(){
	char s[50], x;
	
	printf("Nhap xau ky tu: ");
	gets(s);
	printf("Nhap ky tu x: ");
	scanf("%c", &x);
	
	printf("\nChuoi sau khi thay doi: %s", s);
	doi_ky_tu(s, x);
	printf("\nChuoi sau khi thay doi: %s", s);
}
