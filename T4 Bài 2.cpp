#include<stdio.h>
void gpt_bac_I(int a, int b){
	float x; 
	if(a==0){
		if(b!=0)
			printf("\nPhuong trinh vo nghiem");
		else 
			printf("\nPhuong trinh co vo so nghiem");
	} else{
		printf("\nPhuong trinh co nghiem");
		x=-(float)b/a;
		printf("\nNghiem cua phuong trinh: %.2f", x);
	}
}
int main(){
	int n, m;
	
	printf("Nhap a, b: ");
	scanf("%d%d", &n, &m);
	
	gpt_bac_I(n, m);
}
