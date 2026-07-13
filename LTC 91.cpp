#include <stdio.h>
#include <stdlib.h>
struct NgaySinh{
	int ngay;
	int thang;
	int nam;
};

int main(){
	FILE *f;
	f = fopen("Bai_90.bin", "rb");
	if(f == NULL){
		printf("\nLoi mo file!");
		exit(1);
	}
	// Doc du lieu
	NgaySinh n1;
	fread(&n1, sizeof(struct NgaySinh), 1, f);
	
	printf("\nNgay sinh: %d/%d/%d", n1.ngay, n1.thang, n1.nam);
	fclose(f);
}
