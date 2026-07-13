//#include <stdio.h>
//
//int main() {
//    int n, maxOdd = 1;
//    
//	printf("Nh?p s? nguyên duong: ");
//    scanf("%d", &n);
//    
//        // L?p t? 1 d?n n d? tìm u?c s? l? l?n nh?t
//        for (int i = 1; i <= n; i++) {
//            if (n % i == 0 && i % 2 != 0)
//                maxOdd = i;
//        }
//        printf("U?c s? l? l?n nh?t c?a là: %d" , maxOdd);
//    }
#include "stdio.h"

struct Date{
	int day;
	int month;
	int year;
};

void inputDate(struct Date &d){
	printf("Nhap vao ngay: ");
	scanf("%d", &d.day);
	printf("\nNhap vao thang: ");
	scanf("%d", &d.month);
	printf("\nNhap vao nam: ");
	scanf("%d", &d.year);
}

void printDate(struct Date d){
	printf("%d/%d/%d", d.day, d.month, d.year);
}

int checkDate(struct Date d){
	if((d.year%400==0) || (d.year % 4 == 0 && d.year % 100 != 0))
		return 1;
	else
		return 0;
}

int main(){
	struct Date myDate;
	inputDate(myDate);
	printf("\n---\n");
	printDate(myDate);
//	printf("Kiem tra ngay hop le: %s", checkDate(myDate)==1?"HOP LE":"KHONG HOP LE");
	if(checkDate(myDate))
		printf("\n%d", myDate.year);
	else
		printf("%d kjdivooe", myDate.year);
}
