#include <stdio.h>
#include <math.h>
int LaSNT(int n) {
	if (n < 2) return 0;
	for(int i = 2; i<=sqrt(n);i++) {
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main(){
	int n, dem=0;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	if(n<=1000) {
		for(int i=1;i<=n;i++){
			if(LaSNT(i))
				dem++;
		}
		printf("\nSo luong SNT trong doan[1, %d]: %d", n, dem);
	} else if(n==100000) {
		for(int i=1001;i<=n;i++){
			if(LaSNT(i))
				dem++;
	}
		printf("\nSo luong SNT trong doan[1001, %d]: %d", n, dem);
	}
}
