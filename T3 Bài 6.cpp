#include<stdio.h>
#include<math.h>
int main(){
	int n, sodao, socuoi=0, so_n;
	
	printf("Nhap n (n>0): ");
	scanf("%d", &n);
	
	so_n=n;
	
	while (n > 0) {
    socuoi = n % 10;           
    sodao = sodao * 10 + socuoi;
    n = n / 10;                 
    }
    if(so_n == sodao)
        printf("%d la so doi xung.\n", so_n);
    else
        printf("%d khong la so doi xung.\n", so_n);
		
	if((pow(sqrt(n), 2))== n)
		printf("%d la so chinh phuong", so_n);
	else
		printf("%d khong la so chinh phuong", so_n);
}
