#include <stdio.h>
int main(){
	char color;
	printf("Nhap ky tu: ");
	scanf(" %c", &color);
	switch (color)
	{
		case 'R': printf("RED"); break;
		case 'r': printf("RED"); break;
		case 'G': printf("GREEN"); break;
		case 'g': printf("GREEN"); break;
		case 'B': printf("BLUE"); break;
		case 'b': printf("BLUE"); break;
		default: printf("BLACK");
	}
}
