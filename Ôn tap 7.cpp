#include<stdio.h>
int main(){
	int n, j=1, s=0;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		j=j*i;
		s=s+j; 
		printf("%d! = %d, tong tam thoi = %d\n", i, j, s);

	} 
	printf("Tong tinh duoc: %d", s);
}
