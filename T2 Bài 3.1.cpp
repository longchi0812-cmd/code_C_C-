#include <stdio.h>
int main(){
	float tien, kw, kwtr, kwtn;
	printf("Nhap so kwh thang truoc: ");
	scanf(" %f", &kwtr);
	printf("Nhap so kwh thang nay: ");
	scanf(" %f", &kwtn);
	
	kw = kwtn - kwtr;
	if(kw <= 100)
		tien = kw * 1.418;
	if(kw > 100 && kw <= 150)
		tien = 100 * 1.418 + (kw - 100) * 1.622;
	if(kw > 150 && kw <= 200)
		tien = 100 * 1.418 + 50 * 1.622 + (kw - 150) * 2.044;
	if(kw > 200 && kw <= 300)
		tien = 100 * 1.418 + 50 * 1.622 + 50 * 2.044 + (kw - 200) * 2.210;
	if(kw > 300 && kw <= 400)
		tien = 100 * 1.418 + 50 * 1.622 + 50 * 2.044 + 100 * 2.210 + (kw - 300) * 2.361;
	else if(kw > 400)
			tien = 100 * 1.418 + 50 * 1.622 + 50 * 2.044 + 100 * 2.210 + 100 * 2.361 + (kw - 400) * 2.420;
	
	printf("\n So kw tieu thu: %.0f", kw);
	printf("\n So tien dien phai tra: %.3f", tien);
}
