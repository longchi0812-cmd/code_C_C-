#include<stdio.h>
#include<string.h>
#include<ctype.h>

void doi_xen_ke(char s[]){
	int dem = 0;
	for(int i = 0; i < strlen(s); i++){
		if(isalpha(s[i])){
			if(dem % 2 == 0)
				s[i] = toupper(s[i]);
			else
				s[i] = tolower(s[i]);
			dem++;
		}
		
	}
}

int main(){
	char s[50];
	
	printf("Nhap xau ky tu: ");
	gets(s);
	
	doi_xen_ke(s);	
	printf("%s", s);
}
