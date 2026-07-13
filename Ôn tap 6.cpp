#include<stdio.h>
#include<math.h>
int main(){
	int n;
	
	printf("Nhap so n: ");
	scanf("%d", &n);
	
	if(n<=1){
		printf(" %d khong la so hop", n);
		return 0;
	}
	for(int i=2 ; i<=sqrt(n); i++){
		if(n%i==0){
			printf(" %d la so hop", n);
			return 0;
		}
	}
	printf(" %d khong la so hop", n);
	return 0;
}
