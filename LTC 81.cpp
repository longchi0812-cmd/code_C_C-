#include <stdio.h>
#include <math.h>

struct phanso{
	int  tuso;
	int mauso;
};

void rutgon(phanso *ps){
	int a = ps->tuso;
	int b = ps->mauso;
	
	a = abs(a);
	b = abs(b);
	
	int USCLN =1;
	// TH1
	if(a==0 || b==0){
		USCLN = (a+b);
	}else{
	//TH2
		while(a!=b){
			if(a>b){
				a = a-b;
			}else{
				b = b-a;
			}
		}
		USCLN = a;
	}
	ps->tuso/=USCLN;
	ps->mauso/=USCLN;
}

void nhapphanso(phanso *ps){
	printf("\nNhap vao tu so: ");
	scanf("%d", &ps->tuso);
	
	do{
		printf("\nNhap vao mau so: ");
		scanf("%d", &ps->mauso);
	}while(ps->mauso == 0);
}

void inphanso(phanso ps){
	if(ps.mauso<0){
		ps.mauso*=-1;
		ps.tuso*=-1;
	}
	rutgon(&ps);
	printf("%d/%d", ps.tuso, ps.mauso);
} 


int main(){
	phanso ps1, ps2;
	printf("\nNhap phan so thu nhat: ");
	nhapphanso(&ps1);
	printf("\nNhap phan so thu hai: ");
	nhapphanso(&ps2);
	printf("\nPhan so vua nhap la: ");
	inphanso(ps1);
	printf("\t");
	inphanso(ps2);
	
}

