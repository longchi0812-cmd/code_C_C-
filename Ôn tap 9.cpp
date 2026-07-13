#include <stdio.h>
int main(){
	int n;
	float s=0, a;
	
	do {	
		printf("Nhap a (a>0): ");
		scanf("%f", &a);
	} while(a<=0);
	
	printf("Nhap n: ");
	scanf("%d", &n);
	
	for(int i=0; i<=n; i++) {
		s=s+1/(i+a);		
	}
	printf("Tong s = %.2f", s);
}
