#include <stdio.h>

struct date{
	int day;
	int month;
	int year;
};

void inputdate(struct date &d){
	printf("Nhap vao ngay: ");
	scanf("%d", &d.day);
	printf("Nhap vao thang: ");
	scanf("%d", &d.month);
	printf("Nhap vao nam: ");
	scanf("%d", &d.year);
}

void printf(struct date d){
	printf("%d/%d/%d", d.day, d.month, d.year);
	
}

int checkdate(struct date d){
	if (d.day<0 || d.month<0 || d.year <0)
		return 0;
	
	if(d.month>12)
		return 0;
		
	if (d.month==2){
		if(d.day>28)
			return 0;
	}
	
	if (d.month==1|| d.month==3 || d.month==5|| d.month==7|| d.month==8|| d.month==10|| d.month==12){
		if(d.day>31)
			return 0;
	}
	
	if(d.day>30)
		return 0;
	
	return 1;
}

int main(){
	struct date mydate;
	inputdate(mydate);
	printf("\n---\n ");
	printf(mydate);
	printf("\nKiem tra ngay hop le: %s", checkdate(mydate)==1?"HOP LE":"KHONG HOP LE");
}


