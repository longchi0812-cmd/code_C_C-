#include <stdio.h>

int songaycuathang(int thang, int nam){
	switch(thang){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 11:
			return 30;
		case 2:
			return ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))?29:28; 
	}
}

int ngaytrongnanm(int ngay, int thang, int nam){
	int ntn = 0;
	for(int i = 1; i < thang; i++){
		ntn += songaycuathang(i, nam);
	}
	ntn += ngay;
	return ntn;
}

void inngaytruocdo(int ngay, int thang, int nam){
	if(ngay == 1) {
		if(thang == 1){
			ngay = 31;
			thang = 12;
			nam--;
		}else {
			thang--;
			ngay = songaycuathang(thang, nam);
		}
	}else {
		ngay--;
	}
	printf("\n Ngay truoc do: %d/%d/%d", ngay, thang, nam);
}

void inngaykedo(int ngay, int thang, int nam){
	int nct = songaycuathang(thang, nam);
	if(ngay == nct){
		if(thang == 12){
			ngay = 1;
			thang = 1;
			nam++;
		}else{
			ngay = 1;
			thang++;
		}
	}else {
		ngay++;
	}
	printf("\n Ngay ke do: %d/%d/%d", ngay, thang, nam);
}
int main(){
	int ngay, thang, nam;
	do{
		printf("Nhap vao ngay thang nam: ");
		scanf("%d%d%d", &ngay, &thang, &nam);
	}while(ngay < 1|| ngay > 31 || thang < 1 || thang > 12 || nam < 1);

	// cau a, tim ra so ngay trong thang
	printf("\n So ngay cua thang: %d", songaycuathang(thang, nam));
	
	// cau b, tim ngay trong nam	
	printf("\n Ngay trong nam: %d", ngaytrongnanm(ngay, thang, nam));
	
	// cau c, tm ngay truoc do
	inngaytruocdo(ngay, thang, nam);
	
	// cau d, tm ngay ke do
	inngaykedo(ngay, thang, nam);
	
}
