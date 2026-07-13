#include <stdio.h>

struct Diem2D{
	float x;
	float y;
};

void nhap(struct Diem2D &d){
	printf("Nhap hoanh do x: ");
	scanf("%d", &d.x);
	printf("Nhap tung do y: ");
	scanf("%d", &d.y);
}

void xacdinhtruc(struct Diem2D d){
	if(d.x == 0 && d.y != 0)
		printf("X nam tren truc tung");
	else if(d.y == 0 && d.x != 0)
		printf("X nam tren truc hoang");
	else if(d.x == 0 && d.y == 0)
		printf("X nam tren truc tung va truc hoanh");
	else
		printf("X khong nam tren truc tung hoac truc hoanh");	
}
int main(){
	struct Diem2D x;
	nhap(x);
	xacdinhtruc(x);
}
