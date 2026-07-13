#include <stdio.h>
int main(){
	float x, a, b;
	printf("Nhap a: ");
	scanf("%f", &a);
	printf("Nhap b: ");
	scanf("%f", &b);
	
	if(a!=0){
		x = -b/a;
		printf("Phuong trinh co nghiem x = %.2f", x);
	}else{
		if(b==0)
			printf("Phuong trinh co vo so nghiem");
		else
			printf("Phuong trinh vo nghiem");
	}
}
