#include <stdio.h>

int main(){
	int tuoi;
	char ten[50];
	printf("Nhap vao tuoi cua ban: ");
	scanf("%d", &tuoi);
	getchar();
	
	printf("Nhap vao ten ban: ");
	fgets(ten, sizeof(ten), stdin);
	
	printf("\n Ten da nhap la: ");
	puts(ten);
	printf("\nTuoi: %d", tuoi);
}
