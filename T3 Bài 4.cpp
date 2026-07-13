#include <stdio.h>
#include <math.h> 

int main() {
	int n, s1=0, s3=0, s6=0, s7=0;
	double s2=0, s4=0, s5=1.0; 
	do{
		printf("Nhap n (n>0): ");
		scanf("%d", &n);
	}while(n<=0);

	for (int i = 1; i <= n; i++)
		s1 = s1 + i;
		s1 = s1 / n;
	printf("\n Tong s1: %d", s1);
	
	for (int i = 1; i <= n; i++)
		s2 = s2 + i * i;
		s2 = sqrt(s2);
	printf("\n Tong s2: %.2f", s2);
	
	for (int i = 1; i <= n; i++)
	{
		if(i%2!=0)
		s3 = s3 + pow(i, 2);
	}
	printf("\n Tong s3: %d", s3);
	
	for (int i = 1; i<=n; i++)
		s4 = s4 + (pow((-1), i-1))/pow(2*i, 2);
	printf("\n Tong s4: %.2f", s4);
	
	for (int i = 1; i<=n; i++)
		s5 = s5 * ((2.0*i - 1)/(2.0*i));
	printf("\n Tong s5: %.2f", s5);
	
	for (int i = 1; i <= n; i++)
		s6 = s6 + ((pow((-1), i-1))*i*(i+1)*(i+2));
	printf("\n Tong s6: %d", s6);
	
	int l=1, c=1;
	for (int i = 1; i <= n; i++){
		if(i%2==0)
			c=c*i;
		else
			l=l*i;	
	}
		s7 = c + l;
	printf("\n Tong s7: %d", s7);
}
 
