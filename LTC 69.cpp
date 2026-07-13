#include <stdio.h>
#include <string.h>

int my_strlen(char x[]){
	int count = 0;
	while(x[count]!='\0'){
		count++;
	}
	return count++;
}

int main(){
	char s[100]= "BUI LONG CHI";
	
	printf("\nTen cua ban la: %s", s);
	printf("\nDo dai ten = %d", strlen(s));
	
	printf("\n my_strlen: ");
	printf("\nTen cua ban la: %s", s);
	printf("\nDo dai ten = %d", my_strlen(s));
}
