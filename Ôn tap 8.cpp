#include <stdio.h>
int main(){
	int n, S;
	
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		if(i%3==0)
			S=S+i;
	}
	printf("\nTong cac chu so chia het cho 3 la: %d", S);
}
