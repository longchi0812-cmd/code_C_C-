#include<stdio.h>
int main(){
	int n;
	
	Nhap:
		printf("Nhap n = ");
		scanf("%d", &n);
	if(n<=0) goto Nhap;
	printf("\nDay so le: ");
	for(int i=1; i<=n; i++)
	{
		if(i%2==0) continue;
		printf("\n%d", i);
	}
}
