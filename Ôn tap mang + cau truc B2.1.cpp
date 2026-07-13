#include <stdio.h>
struct MAY{
	char ma_may[10];
	char ten_may[50];
	int toc_do_cpu;
	int Ram;
	char don_gia[50];
};

void nhap(struct MAY &m){
	printf("Nhap ma may: ");
	scanf("\n");
	gets(m.ma_may);
	
	
	printf("Nhap ten may: ");
	scanf("\n");
	gets(m.ten_may);
	
	printf("Nhap toc do cpu (MHz): ");
	scanf("%d", &m.toc_do_cpu);
	
	printf("Nhap RAM (GB): ");
	scanf("%d", &m.Ram);
	
	printf("Nhap don gia: ");
	scanf("\n");
	gets(m.don_gia);
}



int main(){
	struct MAY m1, m2;
	
	printf("Nhap thong tin m1: \n");
	nhap(m1);
	
	printf("\n----\n");
	
	printf("Nhap thong tin m2: \n");
	nhap(m2);
	
	
	printf("\n----\n");
	if(m1.Ram > m2.Ram)
		printf("\nMay %s co dung luong ram lon hon", m1.ten_may);
	else
		printf("\nMay %s co dung luong ram lon hon", m2.ten_may);	
}
