#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int layPhanTu(queue<int> q, int k){
	if(k < 1 || k > q.size()) return -1;
	for(int i = 1; i < k; i++) q.pop();
	return q.front();
}

void daoNguoc(queue<int> &q){
	stack<int> s; 
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

void themPT(stack<int> &s, int k, int e){
	if(k < 1 || k > s.size()){
    	cout << "\nVi tri chen khong hop le";
    	return;
	}
	stack<int> tam;
	for(int i = 1; i < k; i++){
		tam.push(s.top());
		s.pop();
	}
	s.push(e);
	
	while(!tam.empty()){
		s.push(tam.top());
		tam.pop();
	}
}

void in(queue<int> q){
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
}

void in(stack<int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}

int timMIN(stack<int> s){
	int min = INT_MAX;
	while(!s.empty()){
		if(s.top() < min){
			min = s.top();
		}
		s.pop();
	}
	return min;
}
int main(){
	queue<int> q;
	
	q.push(5);
	q.push(1);
	q.push(4);
	q.push(2);
	q.push(3);
	
	if(layPhanTu(q, 2) != -1)
		cout << "Phan tu thu k: " << layPhanTu(q, 3);
	else
		cout << "Vi tri khong hop le.";
		
	daoNguoc(q);
	cout << "\nHang doi sau khi dao nguoc: ";
	in(q);
	
	stack<int> s;
	
	s.push(5);
	s.push(1);
	s.push(4);
	s.push(2);
	s.push(3);
	
	themPT(s, 3, 99);
	cout << "\nNgan xep sau khi them: ";
	in(s);
	
	cout <<"\nPhan tu nho nhat trong ngan xep la: "<< timMIN(s);

	

}
