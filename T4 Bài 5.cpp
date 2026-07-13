#include<stdio.h>
int day_fibonacy(int n){
	int f0=0, f1=1, fn;
	
	printf("\n %d", f0);
	printf("\n %d", f1);
		
	for(int i=2; i<n; i++){
		fn=f0+f1;
		f0=f1;
		f1=fn;
		printf("\n %d", fn);
	}
}
int main(){
	int x, phan_tu;
	
	printf("Nhap n phan tu cua day Fibonacy: ");
	scanf("%d", &x);
	
	day_fibonacy(x);
}
