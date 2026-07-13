#include<stdio.h>
#include<string.h>
int kiem_tra_ten(char a[], char b[]){
	if(!strcmpi(a, b)) // có the dùng strcasecmp()
		return 1;
	else //if(strcmpi(a, b)!=0)
		return 0;
}

int main(){
	char a[100];
	char b[100];
	
	printf("Nhap ten nguoi thu nhat: ");
	gets(a);
	printf("Nhap ten nguoi thu hai: ");
	gets(b);
	
	int kiem_tra = kiem_tra_ten(a, b);
	if(kiem_tra)
		printf("Ten 2 nguoi giong nhau");
	else
		printf("Ten 2 nguoi khong giong nhau");
}
