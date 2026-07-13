#include <stdio.h>
#include <stdlib.h>
struct NgaySinh{
	int ngay;
	int thang;
	int nam;
};
int main(){
	FILE *f;
	// Tao, mo file
	f = fopen("Bai_90.bin", "wb");
	if(f==NULL){
		printf("\nLoi tao, mo file!");
		exit(1);
	}
	// Ghi du lieu
	NgaySinh n1;
	n1.ngay = 12;
	n1.thang = 8;
	n1.nam = 2006;
	
	fwrite(&n1, sizeof(struct NgaySinh), 1, f);
	
	//Dong file
	fclose(f);
	
	return 0;
}
