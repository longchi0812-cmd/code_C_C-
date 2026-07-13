#include<stdio.h>
int main(){
	printf("Bai 003 - Xuat du lieu ra man hinh\n");
	
	int x = 5;
	
	printf("Gia tri x la: %d", x);
	
	float x1 = 3.141555555555;
	
	printf("\nGia tri x1 la: %f", x1);
	printf("\nGia tri x1 la: %.2f", x1);
	float x2 = 5.6;
	float x3 = 2.7;
	printf("\n x2 = %.2f, x3 = %.2f", x2, x3);
	char c = 'A';
	printf("\n %c", c);	
}
/*S? d?ng thu vi?n: stdio.h ? standard input output S? d?ng hàm printf() ? xu?t d? li?u ra b?ng di?u khi?n (console). Cú pháp c?a hàm printf():

printf(“Format string”, Argument_list);

Format string có th? là:

%d (s? nguyên)

%c (ký t?)

%s (chu?i)

%f (float)

%.wf –> d? hi?n th? s? th?c ta s? d?ng, trong dó w là m?t s? t? nhiên và là s? ký t? sau d?u ch?m chúng ta c?n, ví d?: %.2f ? Xu?t ra m?t s? th?c, có ph?n sau d?u ch?m ch? l?y 2 ch? s?.

\n ? xu?ng dòng

Argument_list là tên bi?n ho?c giá tr? c?a các n?i dung c?n xu?t ra màn hình. N?u có nhi?u bi?n thì các bi?n s? du?c ngan cách b?i d?u ph?y.
