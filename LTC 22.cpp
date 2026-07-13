#include<stdio.h>
int main(){
	int n;
	int tong=0;
	printf("Nhap vao n = ");
	scanf("%d", &n);
	
	int i=0;
	while(i<=n){
		tong = tong + i;
		i++;
	}
	printf("\nTong = %d", tong);
}
