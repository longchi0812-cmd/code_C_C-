#include<stdio.h>
int main(){
	int n, k, c;
	int n1=1, k1=1, g1=1;
	Nhap:
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
		printf("Nhap k (k<=n): ");
		scanf("%d", &k);
	} while(k>=n);
	if(n<0 || k<0)
		goto Nhap;
	
	for(int i=1; i<=n; i++){
		n1=n1*i;
	}
	printf("\n n!= %d", n1);
	
	for(int j=1; j<=k; j++){
		k1=k1*j;
	}
	printf("\n k!= %d", k1);
	for(int h=1; h<=(n-k); h++){
		g1=g1*h;
	}
	printf("\n g!= %d", g1);
	c=n1/(k1*g1);
	printf("\n to hop chap %d cua %d = %d", k, n, c);
}
