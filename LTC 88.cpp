#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	
	// 1- tao
	// 2- mo
	f  = fopen("Bai_ 88.txt", "w");
	if(f == NULL){
		printf("\nLoi tao hoac mo file");
		exit(1);
	}
	
	// 3- doc hoac ghi
	int n;
	printf("\nNhap vao so n: ");
	scanf("%d", &n);
	
	fprintf(f, "%d", n);
	// 4- dong file
	fclose(f);
	
	return 0;
}
