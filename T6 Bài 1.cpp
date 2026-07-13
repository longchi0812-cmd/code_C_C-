#include<stdio.h>
#define MAXC 5
void NhapMaTran(int a[][MAXC], int &m, int &n)
{
	printf("Nhap so dong, so cot cua ma tran: ");
	scanf("%d%d", &m, &n);
	
	int i, j;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
		{
			printf("Nhap a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void XuatMaTran(int a[][MAXC], int m, int n)
{
	int i, j;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
int main(){
	int a[4][MAXC];
	int n, m;
	NhapMaTran(a, m, n);
	XuatMaTran(a, m, n);
}
