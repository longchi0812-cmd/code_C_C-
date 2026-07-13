#include<stdio.h>
int main(){
	printf("Cac so hoan hao nho hon 1000 la: ");
	for(int n=6; n<1000; n++){
		int s=0;
		for(int i=1; i<n; i++){
			if(n%i==0)
			s=s+i;
		}
		if(s==n)
			printf("%d ", n);
	}
}
