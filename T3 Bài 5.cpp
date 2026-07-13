#include<stdio.h>
int main(){
	int s=0, f0=0, f1=1, fn, n;
	
	printf("Nhap n (n>=0): ");
	scanf("%d", &n);
	
	for(int i=0; i<=n; i++){
		if(i==0)
			fn=0;
		else if(i==1)
			fn=1;
			else if(i>=2)
				fn=f0 + f1;
				f0=f1;
				f1=fn;
	s=s+fn;
	}
	printf("Tong day Fibonacci la: %d", s);	
}
