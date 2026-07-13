#include <iostream>
using namespace std;

void inputArr(int a[], int &n){
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Nhap so thu " << i << " : " ;
		cin >> a[i];
	}
}

void outputArr(int a[], int n){
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

float avgArr(int a[], int n){
	float s = 0;
	for(int i = 0; i < n; i++){
		s+=a[i];
	}
	return s/n;
}

bool findArr(int a[], int n, int x){
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			return true;
		}
	}
	return false;
}

void sortArr(int a[], int n){
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

int mergeArr(int a[], int n, int b[], int m, int c[]){
	int i = 0; 
	int j = 0; 
	int k = 0;
	
	while(i < n && j < m){
		if(a[i] < b[j]){
			c[k++] = a[i++];
		} else {
			c[k++] = b[j++];
		}
	}
	
	while(i < n){
		c[k++] = a[i++];
	}
	while(j < m){
		c[k++] = b[j++];
	}
}

int countArr(int a[], int n, int b[], int d[]){
	int m = 0;
	
	for(int i = 0; i < n; i++){
		int vitri = -1;
		for(int j = 0; j < m; j++){
			if(b[j] == a[i]){
				vitri = j;
				break;
			}
		}
		if(vitri != -1){
			d[vitri]++;
		} else {
			b[m] = a[i];
			d[m] = 1;
			m++;
		}
	}
	return m;
}

int main(){
	int a[10], n;
	int b[10], m;
	int c[20], d[10];
	
	inputArr(a, n);
	cout << "Mang da nhap: ";
	outputArr(a, n);
	
	cout << "\n--------\n";
	
	inputArr(b, m);
	cout << "Mang da nhap: ";
	outputArr(b, n);
	
	cout << "\n--------\n";
	cout << "\nTrung binh cong cua mang: " << avgArr(a, 2);
	
	if(findArr(a, n, 2)){
		cout << "\nCo so nguyen trong mang";
	}else {
		cout << "\nKhong co so nguyen trong mang";
	}
	cout << "\n--------\n";
	cout << "\nMang a tang dan: ";
	sortArr(a, n);
	outputArr(a, n);
	
	cout << "\nMang b tang dan: ";
	sortArr(b, m);
	outputArr(b, m);
	
	cout << "\nMang da ghep: ";
	mergeArr(a, n, b, m, c);
	outputArr(c, n + m);
	
	int p = countArr(a, n, b, d);
	cout << "\nCac so khac nhau: ";
	outputArr(b, p);
	
	cout << "\nSo lan xuat hien: ";
	outputArr(d, p);
	
}
