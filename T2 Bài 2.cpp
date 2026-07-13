#include<stdio.h>
main(){
	char ch;
	printf("Nhap mot chu cai: ");
	scanf(" %c", &ch);
    if (65 <= ch && ch < 97)
    ch = ch + 32;
    else if (97 <= ch && ch <= 129)
    ch = ch - 32;
    printf(" %c", ch);
}
