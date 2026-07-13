#include<stdio.h>
main(){
	float a,x,b;
	printf("Nhap a,b: ");
	scanf("%f%f", &a, &b);
	if (a == 0)
		if (b == 0) 
            printf("\n Phuong trinh vo so nghiem");
        else 
			printf("\n Phong trinh vo nghiem");
	else if (a != 0)
		printf("\n Phuong trinh co nghiem");
		x = -b / a;
		printf("\n Nghiem cua phuong trinh: %.2f", x);
}
