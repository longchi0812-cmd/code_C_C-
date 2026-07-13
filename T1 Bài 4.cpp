#include <stdio.h>
int main(){
	float r, S, CV;
	printf("Nhap ban kinh r: ");
	scanf("%f", &r);
	CV = r * 2 * 3.14;
	S = r * r * 3.14;
	printf("\n Chu vi hinh tron la: %.2f", CV);
	printf("\n Dien tich hinh tron la: %.2f", S);
}
