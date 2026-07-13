//17
#include "stdio.h"
int main(){
	int n;
	printf("Nhap vao so n (tu 1 den 7): ");
	scanf("%d", &n);
	
	switch(n){
		case 1:
				printf("\n Chu Nhat");
				break;
		
		case 2:
				printf("\n Thu Hai");
				break;
		
		case 3:
				printf("\n Thu Ba");
				break;
		
		case 4:
				printf("\n Thu Tu");
				break;
		
		case 5:
				printf("\n Thu Nam");
				break;
		
		case 6:
				printf("\n Thu Sau");
				break;
		
		case 7:
				printf("\n Thu Bay");
				break;
				
		default:
				printf("Nhap vao so n khong dung!");		
		
	}
}
