#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("\nNhap so luong phan tu mang: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n){
	printf("\nGia tri cua mang la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

int kiemTraMangCon(int a[], int n1, int b[], int n2){
	int kq = 0;
	if(n2 <= n1){
		for(int i = 0; i < n1; i++){
			if(a[i] == b[0]){
				int j = 0;
				for(; j < n2; j++){
					if(a[i+j] != b[j])
						break;
				}
				if(j == n2)
					kq = 1;
			}
		}
	}
	return kq;
}

int main(){
	int a[10], n1;
	int b[10], n2;
	
	nhapmang(a, n1);
	xuatmang(a, n1);
	
	nhapmang(b, n2);
	xuatmang(b, n2);
	
	int kt = kiemTraMangCon(a, n1, b, n2);
	if(kt){
		printf("\nMang b la mang con cua a: ");
	}else{
		printf("\nMang b khong la mang con cua mang a: ");
	}
}
