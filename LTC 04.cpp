#include <stdio.h>
int main(){
	int x;
	float y;
	char c;
		// Nhap so nguyen
		printf("Nhap vao gia tri cua x: ");
		scanf("%d", &x);
		printf("\n Gia tri x da nhap la: %d", x);
		
		// Nhap vao so thuc
		printf("\n Nhap vao gia tri cua y: ");
		scanf("%f", &y);
		printf("\n gia tri y da nhap la: %.2f",y);
		
		// Nhap vao ky tu
		printf("\n Nhap ki tu c: %c", c);
		scanf("%c", &c);
		printf("\n ki tu c la: %c", c);
		*/
		// Nhap nhieu du lieu cung mot hang
		float x1, x2, x3;
		printf("Nhap vao gia tri cua x1, x2, x3");
		scanf("%f%f%f", &x1, &x2, &x3);
		printf("x1=%f, x2=%f, x3=%f", x1, x2, x3);					
}

