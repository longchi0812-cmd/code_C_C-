#include <iostream>
#include <stack>

using namespace std;

void heNhiPhan(stack<int> &s, int n){
	while(n != 0){
		s.push(n%2);
		n/=2;
	}
}


void heBatPhan(stack<int> &s, int n){
	while(n != 0){
		s.push(n%8);
		n/=8;
	}
}

void heThapLucPhan(stack<char> &s3, int n){
	while(n != 0){
		if(n % 16 >= 10){
			s3.push((n % 16) - 10 + 'A');
		} else if(n % 16 < 10) {
			s3.push((n % 16) + '0');
		}
		n /= 16;
	}
}

int main(){
	stack<int> s;
	stack<char> s3;
	int n;
	
	cout << "Nhan so he thap phan: ";
	cin >> n;
	
	heNhiPhan(s, n);
	cout << "He nhi phan cua " << n << " la: ";
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	
	heBatPhan(s, n);
	cout << "\nHe bat phan cua " << n << " la: ";
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	
	heThapLucPhan(s3, n);
	cout << "\nHe thap luc phan cua " << n << " la: ";
	while(!s3.empty()){
		cout << s3.top();
		s3.pop();
	}
}
