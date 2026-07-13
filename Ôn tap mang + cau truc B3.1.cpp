#include <stdio.h>
#include <math.h>

struct TamGiac{
	float canhA;
	float canhB;
	float canhC;
};

void nhap(struct TamGiac &tg){
	printf("Nhap do dai canh A: \n");
	scanf("%f", &tg.canhA);
	printf("Nhap do dai canh B: \n");
	scanf("%f", &tg.canhB);
	printf("Nhap do dai canh C: \n");
	scanf("%f", &tg.canhC);
}

int check(struct TamGiac tg){
	if(tg.canhA + tg.canhB > tg.canhC && tg.canhA + tg.canhC > tg.canhB && tg.canhB + tg.canhC > tg.canhA)
		return 1;
	return 0;
}

float dientichtg(struct TamGiac tg){
	float p = 0;
	p = tg.canhA + tg.canhB + tg.canhC;
	p = p / 2;
	float s = 0;
	s = sqrt(p*(p-tg.canhA)*(p-tg.canhB)*(p-tg.canhC));
	
	return s;
}

int main(){
	struct TamGiac tg1;
	
	printf("Nhap do dai tam giác: \n");
	nhap(tg1);
	
	if(check(tg1) == 1)
		printf("3 canh la tam giac");
		printf("\nDien tich tam giac: %.2f", dientichtg(tg1));
	else
		printf("3 canh khong phai la tam giac");

}
