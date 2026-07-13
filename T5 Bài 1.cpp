#include<stdio.h>

void nhapmang(int a[], int &n)
{
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		printf("\n a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void xuatmang(int a[], int n)
{
	printf("Noi dung cua mang la: ");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
		
	printf("\n");
}

int dem_so(int a[], int n){
	int dem=0;
	for(int i=0; i<n; i++){
		if(a[i]%4==0 && a[i]%5!=0)
			dem++;
	}
	printf("Co %d so thoa man dieu kien", dem);
}
int check_snt(int n){
	if(n<2)
		return 0;
	for(int i=2; i*i<=n; i++){
		if(n%i==0)
			return 0;
	}
	return 1;	
}
int tong_snt(int a[], int n){
	int s=0;
	for(int i=0; i<n; i++){
		if(check_snt(a[i]))
			s += a[i];
	}
	printf("\nTong cac so nguyen to la: %d", s);
}
int main(){
	int a[10], n;
	
	nhapmang(a, n);
	xuatmang(a, n);
	dem_so(a, n);
	tong_snt(a, n);
}
