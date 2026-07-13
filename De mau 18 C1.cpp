#include <stdio.h>

void nhapmang(float a[], int &n){
	printf("Nhap so luong phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 1; i< n + 1; i++){
		printf("a[%d] = ", i);
		scanf("%f", &a[i]);
	}	
}

void invitrichan(float a[], int n){
	printf("Can phan tu o vi tri chan: ");
	for(int i = 1; i < n+1; i++){//  for (int i = 0; i < n; i += 2)
		if(i % 2==0)
			printf("%.2f ", a[i]);
	}
	printf("\n");		
}

int dem(float a[], int n, float x){
	int dem = 0;
	for(int i = 1; i < n+1; i++){
		if(a[i] > x)
			dem++;
	}
	return dem;
}

float timmax(float a[], int n){
	float max = a[1];
	for(int i = 2; i < n + 1; i++){
		if(max < a[i])
			max = a[i];
	}
	return max;
}

void ghifile(float a[], int n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "w");
	if(f == NULL){
		printf("Loi mo file\n");
		return;
	}
	fprintf(f, "%d\n", n);
	for(int i = 1; i < n + 1; i++){
		fprintf(f, "%f ", a[i]);
	}
	fclose(f);
}

void docfilevatimMAX(float a[], int &n, char tenfile[50]){
	FILE *f;
	f = fopen(tenfile, "r");
	if(f == NULL){
		printf("Loi mo file\n");
		return;
	}
	fscanf(f, "%d", &n);
	
	for(int i = 1; i < n + 1; i++){
		fscanf(f, "%f ", &a[i]);
	}
	fclose(f);
	
	float max = timmax(a, n);
	printf("\nSo lon nhat trong file la: %.2f", max);
}



int main(){
	float a[10], x;
	int n;
	
	nhapmang(a, n);
	
	printf("Nhap x: ");
	scanf("%f", &x);
	
	invitrichan(a, n);
	
	if(dem(a, n, x) > 0)
		printf("Co %d so lon hon %.2f", dem(a, n ,x), x);
	else
		printf("Khong co so nao lon hon %.2f", x);
		
	printf("\nVi tri cac so bang so lon nhat la: ");
	for(int i = 1; i < n + 1; i++){
		if(a[i] == timmax(a, n))
			printf("%d ", i);
	}
	
	ghifile(a, n, "sothuc.txt");
	docfilevatimMAX(a, n, "sothuc.txt");		
}
