#include<stdio.h>
#include<math.h>
int kiem_tra_SNT(int x) {
	//snt có toi da 2 uoc sô
	//snt là nhung so lon hon 1
	if(x<=1)
		return 0;

	for(int i=2; i<=x-1; i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}
int main(){
	int n; 
	printf("Nhap vao n: ");
	scanf("%d", &n);
	
	//goi ham
	int kt = kiem_tra_SNT(n);
	//int kt = kiem_tra_SNT(n); n no se thay cho x

	if(kt==1)
		printf("La so nguyen to");
	else
		printf("Khong la so nguyen to");
}
