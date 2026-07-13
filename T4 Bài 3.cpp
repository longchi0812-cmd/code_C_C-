#include<stdio.h>
#include<math.h>
void gpt_bac_2(int a, int b, int c){
	float deta, x1, x2;
	
	if(a==0)
		printf("He so a phai khac khong");
	else {
		deta=b*b-4*a*c;
	if(deta<0)
		printf("Phuong trinh vo nghiem");
	else if(deta>0){
		printf("Phuong trinh co 2 nghiem phan biet");
		x1=(-b+sqrt(deta))/(2*a);
		x2=(-b-sqrt(deta))/(2*a);
		printf("\nx1= %.2f", x1);
		printf("\nx2= %.2f", x2);					
	} else{
		printf("Phuong trinh co nghiem kep");
		x1=x2=-(float)b/(2*a);
		printf("\nx= %.2f", x1);		
		}
	}
}
int main(){
	int x, y, z;
	
	printf("Nhap a, b, c: ");
	scanf("%d %d %d", &x, &y, &z);
	
	gpt_bac_2(x, y, z);
}
