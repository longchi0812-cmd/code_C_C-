#include<stdio.h>
#include<string.h>
int check_ky_tu(char s[], char c){
	for(int i=0; i< strlen(s); i++){
		if(s[i]==c)
			return 1;
	}
	return 0;
}
int dem_ky_tu(char s[],char c){
	int dem =0;
	for(int i=0; i < strlen(s); i++){
		if(s[i]==c)
			dem++;
	}
	return dem;
}
int main(){
	char s[100], c;
	
	printf("Nhap vao mot chuoi: ");
	gets(s);
	printf("Nhap vao mot ky tu: ");
	scanf("%c", &c);
	
	if(check_ky_tu(s, c))
		printf("ky tu %c co trong chuoi", c);
	else
		printf("ky tu %c khong co trong chuoi", c);
			
	int ky_tu=dem_ky_tu(s, c);
	printf("\nSo lan xuat hien la: %d", ky_tu);
}
