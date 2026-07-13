#include<stdio.h>
int main(){
	int a, b, USCLN;
	
	printf("Nhap vao hai so nguyen a b: ");
	scanf("%d%d", &a, &b);
	//th1
	if(a==0 || b==0)
		USCLN = (a+b);
	else
		//th2
		while(a!=b){
			if(a>b)
				a = a-b;
			else
				b = b-a;
		}
		USCLN = a;
	printf("USCLN = %d", USCLN);
				
}
