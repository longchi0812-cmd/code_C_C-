#include<stdio.h>
#include<math.h>
int main(){
	int n, check=1;
	
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	
	if(n<2)
		check=0;
	else{
		for(int i=2; i*i<=n; i++){
			if(n%i==0){
				check=0;
				break;
			}
		}
	}
	if(check)
		printf("%d la so nguyen to", n);
	else
		printf("%d khong phai la so nguyen to", n);
}

