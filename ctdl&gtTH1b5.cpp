#include <iostream>
using namespace std;

const int MAXROWS = 100;
const int MAXCOLS = 100;

void inputArr2D(int arr[][MAXCOLS], int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << "[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
}

void printArr2D(int arr[][MAXCOLS], int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void addArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int n, int c[][MAXCOLS]){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

int maxArr2D(int arr[][MAXCOLS], int m, int n, int &rowMax, int &colMax){
	int max = arr[0][0];
	rowMax = 0; 
	colMax = 0;
	
	for(int i = 0; i <  m; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] > max){
				max = arr[i][j];
				rowMax = i;
				colMax = j;
			}
		}
	}
	return max;
}

void multiplyArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int p, int n, int c[][MAXCOLS]){
	for(int i = 0; i< m; i++){
		for(int j = 0; j < n; j++){
			c[i][j] = 0;
			for(int k = 0; k < p; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main(){
	int m, n;
	int p = 3;
	int rowMax, colMax;
	
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	int a[MAXROWS][MAXCOLS];
	inputArr2D(a, m, n);
	cout << "Cac phan tu trong mang:\n";
	printArr2D(a, m, n);
	
	int b[MAXROWS][MAXCOLS];
	inputArr2D(b, m, n);
	cout << "Cac phan tu trong mang:\n";
	printArr2D(b, m, n);
	
	cout <<"\n-------\n";
	
	int c[MAXROWS][MAXCOLS];
	addArr2D(a, b, m, n, c);
	cout << "Ket qua cong hai ma tran:\n";
	printArr2D(c, m, n);
	
	maxArr2D(a, m, n, rowMax, colMax);
	cout << "Vi tri so lon nhat:[" << rowMax << "][" << colMax << "]";
	
	cout <<"\n-------\n";
	
	inputArr2D(a, m, p);
	cout << "Cac phan tu trong mang:\n";
	printArr2D(a, m, p);
	
	inputArr2D(b, p, n);
	cout << "Cac phan tu trong mang:\n";
	printArr2D(b, p, n);
	
	cout <<"\n-------\n";
	
	multiplyArr2D(a, b, m, p, n, c);
	cout << "Ket qua nhan hai ma tran:\n";
	printArr2D(c, m, n);
}

