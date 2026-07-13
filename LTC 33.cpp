#include <stdio.h>

void printfnhiphan(int x){
	if(x==0)
		return;
	else{
		int r = x%2;
		printfnhiphan(x/2);
		printf("%d", r);
	}
}

int main(){
	int n ;
	do{
		printf("Nhap vao n: ");
		scanf("%d", &n);
	}while(n < 0);
	
	printfnhiphan(n);
}
