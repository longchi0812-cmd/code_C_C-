#include <stdio.h>
#include <string.h>

int my_strlen(char x[]){
	int count = 0;
	while(x[count]!='\0'){
		count++;
	}
	return count++;
}

void xoaxuongdong(char x[]){
	size_t len = strlen(x);
	
	if(x[len-1]=='\n'){
		x[len]=='\0';
	}
}

int main(){
	char s[100]= "BUI LONG CHI";
	xoaxuongdong(s);
	
	printf("\nTen cua ban la: %s", s);
	printf("\nDo dai ten = %d", strlen(s));
	
	printf("\n my_strlen: ");
	printf("\nTen cua ban la: %s", s);
	printf("\nDo dai ten = %d", my_strlen(s));
}
