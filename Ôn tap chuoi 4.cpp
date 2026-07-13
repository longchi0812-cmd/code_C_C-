#include<stdio.h>
#include<string.h>
#include<ctype.h>

int la_nguyen_am(char c){
	c = tolower(c);
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	return 0;
}

void tim_vt(char s[]){
	int vt_dau = -1, vt_cuoi = -1;
	for(int i = 0; i < strlen(s); i++){
		if(la_nguyen_am(s[i])){
			if(vt_dau == -1)
			vt_dau = i;
		vt_cuoi = i;
		}
	}
		
 if(vt_dau == -1)
    printf("Khong co nguyen am trong chuoi.\n");
else
    printf("Vi tri dau tien: %d\nVi tri cuoi cung: %d\n", vt_dau, vt_cuoi);
}
int main(){
	char s[50];
	
	printf("Nhap xau ky tu: ");
	gets(s);
	
	tim_vt(s);
}
