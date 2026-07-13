#include <stdio.h>
#include <string.h>

char ky_tu_k(char s[], int k){
	if(k >= 1 && k <= strlen(s))
		return s[k-1];
	else
		return 0;
			
}

int main(){
	int k;
	char s[100];
	
	printf("Nhap ki tu xau: ");
	gets(s);

	printf("Nhap so nguyen k: ");
	scanf("%d", &k);
	
	//char ket_qua=ky_tu_k(s, k);
	
	if(ky_tu_k(s, k) != 0)
		printf("ky tu vt %d trong chuoi la: %c", k, ky_tu_k(s, k));
	else
		printf("Vi tri k khong hop le");
}
