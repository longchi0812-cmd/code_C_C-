#include <stdio.h>
#include <math.h>
int La_snt(int n){
	if(n < 2)
		return 0;
	for(int i = 2; i <=sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}
void nhapmang(int a[], int &n){
	do{
		printf("Nhap phan tu mang(n<=10): ");
		scanf("%d", &n);
	}while(n < 10);
	
	int m = 2;
	int k = 0;
	while(k < n){
		if(La_snt(m)){
			a[k] = m;
			k++;
		}
		m++;
	}
}
//void nhapmang(int a[], int &n){
//    do {
//        printf("Nhap phan tu mang(n<=10): ");
//        scanf("%d", &n);
//    } while(n > 10);
//
//    int m = 2;  // B?t d?u ki?m tra t? s? 2
//    for (int i = 0; i < n; ) {  // ch? tang i khi tìm du?c SNT
//        if (La_snt(m)) {
//            a[i] = m;
//            i++;     // Ch? tang i n?u m là s? nguyên t?
//        }
//        m++;         // Luôn tang m d? ki?m tra s? ti?p theo
//    }
//}

void xuatmang(int a[], int n){
	//printf("Noi dung cua mang la: ");
	for(int i = 0; i < n; i++){
		printf("%d\n ", a[i]);
	}
	printf("\n");
}

int main(){
	int a[10], n;
	int b[10], c[10];
	
	nhapmang(a, n);
	xuatmang(a, n);

}
