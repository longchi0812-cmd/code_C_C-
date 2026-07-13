#include <stdio.h>

void nhapmang(int a[], int &n){
	printf("Nhap so luong phan tu mang: ");
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

void sapxeptangdan(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]){
				int tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}

void tronmang(int a1[], int n1, int a2[], int n2, int a3[], int &n3){
	n3 = n1 + n2;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	while(i3<n3){
		if(i1 >= n1){
			a3[i3] = a2[i2];
			i2++;
		}else if(i2 >= n2){
			a3[i3] = a1[i1];
			i1++;
		}else if(a1[i1] < a2[i2]){
			a3[i3] = a1[i1];
			i1++;
		}else{
			a3[i3] = a2[i2];
			i2++;
		}
		i3++;
	}
}

int main(){
	int n1, n2, n3;
	int a[10], b[10], c[20];
	
	printf("\n");
	nhapmang(a, n1);
	xuatmang(a, n1);
	sapxeptangdan(a, n1);
	xuatmang(a, n1);
	printf("\n");
	nhapmang(b, n2);
	xuatmang(b, n2);
	sapxeptangdan(b, n2);
	xuatmang(b, n2);
	printf("\n");
	tronmang(a, n1, b, n2, c, n3);
	xuatmang(c, n3);
}
