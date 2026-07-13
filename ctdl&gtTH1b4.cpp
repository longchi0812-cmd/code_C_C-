#include <iostream>
using namespace std;

int* inputDynamicArr(int n){
	int* arr = new int [n];
	cout << "Nhap cac phan tu:\n";
	for(int i = 0; i < n; i++){
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	return arr;
}

void printDynamicArr(int *arr, int n){
	cout << "\nCac phan tu vua nhap: ";
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}

void appendDynamicArr(int* arr, int &n, int x){
	arr[n] = x;
    n++;
}

int main(){
	int n;
	
	cout << "Nhap n: ";
	cin >> n;
	
	int* arr =  inputDynamicArr(n);
	printDynamicArr(arr, n);
	
	appendDynamicArr(arr, n, 99);
	cout << "\nMang sau khi them: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
