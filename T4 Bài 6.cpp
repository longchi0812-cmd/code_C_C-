#include<stdio.h>

int check_snt(int n){
	if(n<2)
		return 0;
	else {
		for(int i=2; i*i<n; i++){
			if(n%i==0)
				return 0;
		}
		return 1; 
	}
} 

int so_doi_xung(int n){
	int sodao, sodau, m=0;
	sodau = n;
	
	while(n>0){
		m=n%10;
		sodao=sodao*10+m;
		n=n/10; 
	}
	if(sodau=sodao)
		return 1;
	else
		return 0; 
} 
/*
int tong_chu_so_nguyen_to(int n) {
    int tong = 0;
    while (n > 0) {
        int cs = n % 10;
        if (cs == 2 || cs == 3 || cs == 5 || cs == 7)
            tong += cs;
        n /= 10;
    }
    return tong;
}

int tong_chu_so_chinh_phuong(int n) {
    int tong = 0;
    while (n > 0) {
        int cs = n % 10;
        if (cs == 0 || cs == 1 || cs == 4 || cs == 9)
            tong += cs;
        n /= 10;
    }
    return tong;
}
*/
int main(){
	int x;
	
	printf("Nhap so nguyen duong n (n>0): ");
	scanf("%d", &x);
	
	if(check_snt(x))
		printf("\n %d la so nguyen to", x);
	else
		printf("\n %d khong la so nguyen to", x);
	
	if(so_doi_xung(x))
		printf("\n %d la so doi xung", x);
	else
		printf("\n %d khong la so doi xung", x);
	/*	
	printf("\n %d Tong cac chu so nguyen to: %d\n", tong_chu_so_nguyen_to(x));
    printf("\n %d Tong cac chu so chinh phuong: %d\n", tong_chu_so_chinh_phuong(x));
    */
} 

