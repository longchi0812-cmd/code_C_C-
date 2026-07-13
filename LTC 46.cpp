#include <stdio.h>
#include <conio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so phan tu mang: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	printf("\nNoi dung cua mang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

void themvitridau(int a[], int &n, int x){
	n++;
	for(int i = n - 1; i > 0; i--){
		a[i] = a[i - 1];
	}
	a[0] = x;
}

void themvitricuoi(int a[], int &n, int x){
	a[n] = x;
	n++;
}

// nhap n = 3
// nhap x = 99, k = 2
// cac so con lai nhap theo thu tu
void chenvitrik(int a[], int &n, int x, int k){
	n++; // n = 4
	for(int  i = n - 1; i > k; i--){
		a[i] = a[i - 1];
	}
	a[k] = x; 
	// 0 1 2 3
}	// 1 2 3 
	// i = 4 - 1 = 3 , tmdk, i = 2;
	// a[3] = a[2]
	// 0 1 2 3
	// 1 2   3
	// 1 2 99 3

int main(){
	int a[10], n;
	
	char gt;
		
	do{
		printf("\n--------------------------\nMENU (chon ham muon xu ly)\n");
		printf("1 - Nhap mang\n");
		printf("2 - Xuat mang\n");
		printf("3 - Them phan tu vao cuoi mang\n");
		printf("4 - Them phan tu vao dau mang\n");
		printf("5 - Them phan tu vao vi tri k\n");
		printf("x - Thoat\n");
		printf("Lua chon cua ban la: ");
		scanf(" %c", &gt);//them khoang trang truoc %c de ko bi lap lai MENU
		//
		if(gt == '1'){
			nhapmang(a, n);
		}
		else if(gt == '2'){
			xuatmang(a, n);
		}
		else if(gt == '3' || gt == '4' || gt == '5'){
			int m;
			printf("\nNhap vao m = ");
			scanf("%d", &m);
			
			if(gt == '3'){
				themvitricuoi(a, n, m);
			}else if(gt =='4'){
				themvitridau(a, n, m);
			}else if(gt == '5'){
				int k;
				printf("\nNhap vao k = ");
				scanf("%d", &k);
				chenvitrik(a, n, m, k);
			}
		}	
	}while(gt != 'x');
}
