#include <stdio.h>

void nhapmang(float a[], int &n){
	printf("Nhap so luong phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}

float s_vi_tri_le(float a[], int n){
	float s = 0;
	for(int i = 0; i < n; i++){
		if(i % 2 != 0)
			s =s + a[i];
	}
	return s;
}

int timsolancan(float a[], int n, int &vt1, int &vt2){
	for(int i = 1; i < n-1; i++){
		float tb = (a[i-1] + a[i+1]) / 2; 
		if( tb == a[i]){
			vt1 = i - 1;
			vt2 = i + 1;
			return 1;
		}
	}
	return 0;
}

void ghifile(float a[], int n, char tenfile[]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f == NULL){
		printf("Loi tao hoac mo file!");
		return;
	}
	
	fprintf(f, "%d\n", n);
	for(int i = 0; i < n; i++){
		fprintf(f, "%.2f ", a[i]);
	}
	fclose(f);
}

void docfilevadem(float a[], int &n, char tenfile[]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f == NULL){
		printf("Loi mo file!");
		return;
	}
	
	fscanf(f, "%d\n", &n);
	for(int i = 0; i < n; i++){
		fscanf(f, "%.2f ", &a[i]);
	}
	int dem = 0;
	for(int i = 0; i<n; i++){
		if(a[i] > 0)
			dem++;
	}
	printf("Co %d so duong", dem);
	
	fclose(f);
}


int main(){
	float a[10];
	int n;
	int vt1, vt2;
	
	nhapmang(a, n);
	ghifile(a, n, "Sothuc.txt");
	docfilevadem(a, n, "Sothuc.txt");

	printf("\nTong cac so o vi tri le = %.2f", s_vi_tri_le(a, n));
	if(timsolancan(a, n, vt1, vt2)) {
        printf("\nVi tri 2 so lan can la: %d va %d", vt1, vt2);
    }else {
    printf("\nKhong co so nao o giua bang trung binh cong 2 so lan can.");
    }

}
	
