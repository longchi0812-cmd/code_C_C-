/*
#include <stdio.h>
int main(){
	int n, a, b, c;
	
	 for(int i=100;i<=999;i++)
	 {
	 	a=i/100;
	 	b=(i/10)%10; 
	 	c=i%10;
	 	n=a*a*a+b*b*b+c*c*c;
	 	
	 	if(n==i)
	 		printf("So tim duoc la: %d\n", i);
	 }
}
*/

#include <stdio.h>
int main(){
	float n;
	
	printf("Nhap thang diem he 10 n: ");
	scanf("%f", &n);
	
	if(n<4.0) {
		printf("Thang diem he 4 la: 1.0\n");
		printf("Thang diem he chu la: F\n");
	} else if(n<5.0) {
		printf("Thang diem he 4 la: 1.5\n");
		printf("Thang diem he chu la: D\n");
	} else if(n<6.0) {
		printf("Thang diem he 4 la: 2.0\n");
		printf("Thang diem he chu la: C\n");
	} else if(n<7.0) {
		printf("Thang diem he 4 la: 2.5\n");
		printf("Thang diem he chu la: B\n");
	} else if(n<8.0) {
		printf("Thang diem he 4 la: 3.0\n");
		printf("Thang diem he chu la: B+\n");
	} else if(n<9.0) {
		printf("Thang diem he 4 la: 3.5\n");
		printf("Thang diem he chu la: A\n");
	} else if(n>=9.0) {
		printf("Thang diem he 4 la: 4.0\n");
		printf("Thang diem he chu la: A+\n");
	}
}
