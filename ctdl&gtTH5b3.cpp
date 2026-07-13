#include <iostream>
#include <stack>

using namespace std;

void daoNguocArr(int a[], stack<int> &s){
	for(int i = 0 ; i < 5; i++){
		s.push(a[i]);	
	}
	
	for(int i = 0 ; i < 5; i++){
		a[i] = s.top();
		s.pop();
	}
}

int main(){
	stack<int> s;
	int a[] = {1, 2, 3, 4, 5};
	
	daoNguocArr(a, s);
	cout << "Mang sau khi dao: ";
	for(int i = 0; i < 5; i++){
		cout << a[i] << " ";
	}
}
