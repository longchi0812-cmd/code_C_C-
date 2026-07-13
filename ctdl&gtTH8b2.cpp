#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string hoten;
    double dtb; 
};

void swap(SinhVien &a, SinhVien &b){
    SinhVien tmp = a;
    a = b;
    b = tmp;
}

void siftDown(SinhVien arr[], int i, int n){
    int maxIndex = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if	(left < n && arr[left].dtb < arr[maxIndex].dtb)
        maxIndex = left;

    if (right < n && arr[right].dtb < arr[maxIndex].dtb)
        maxIndex = right;

    if (i != maxIndex){
        swap(arr[i], arr[maxIndex]);
        siftDown(arr, maxIndex, n);
    }
}

void heapSort(SinhVien arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--)
        siftDown(arr, i, n);
        
    for (int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        siftDown(arr, 0, i);
    }
}

int main(){
    int n = 10;
    SinhVien arr[100];

    arr[0] = {"Nguyen Van A", 7.5};
    arr[1] = {"Tran Thi B", 9.0};
    arr[2] = {"Le Van C", 6.8};
    arr[3] = {"Pham Thi D", 8.2};
    arr[4] = {"Hoang Van E", 5.5};
    arr[5] = {"Vo Thi F", 9.3};
    arr[6] = {"Bui Van G", 7.0};
    arr[7] = {"Do Thi H", 8.8};
    arr[8] = {"Pham Van I", 6.0};
    arr[9] = {"Ly Thi K", 7.9};

    cout << "Danh sach truoc khi sap xep:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i].hoten << " - " << arr[i].dtb << endl;
	}
    heapSort(arr, n);

    cout << "\nDanh sach sau khi sap xep theo thu tu giam:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i].hoten << " - " << arr[i].dtb << endl;
	}
    return 0;
}

