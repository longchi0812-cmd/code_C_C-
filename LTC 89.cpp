#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	//1, 2 Tao, mo file
	f = fopen("Bai_ 88.txt", "r");
	if(f==NULL){
		printf("\nLoi tao hoac mo file!");
		exit(1);
	}
	//3 Doc du lieu
	int n;
	fscanf(f, "%d", &n);
	printf("\nGia tri cua n: %d", n);
	
	//4 Dong file
	fclose(f);
}
