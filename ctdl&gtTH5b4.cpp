#include <iostream>
#include <stack>

using namespace std;

int douutien(char op){
	if(op == '+' || op == '-') return 1;
	if(op == '*' || op == '/' || op == '%') return 2;
	if(op == '^') return 3;
	return 0;
}

string chuyenhauto(string inf){
	string btht = "";
	stack<char> s;
	
	for(char c : inf){
		if(isalnum(c)){
			btht += c;
		}
		else if(c == '('){
			s.push(c);
		}
		else if(c == ')'){
			while (!s.empty() && s.top() != '(') {
                btht += s.top();
                s.pop();
            }
            s.pop(); 
        } 
        else {
            while (!s.empty() && douutien(s.top()) >= douutien(c)) {
                btht += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        btht += s.top();
        s.pop();
    }

    return btht;
}

int tinhHauTo(string btht) {
    stack<int> s;

    for (char c : btht) {
        if (isdigit(c)) {
            s.push(c - '0'); 
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.top(); 
}

int main(){
	string bieuthuc;
	cout << "Nhap bieu thuc trung to: ";

	cin >> bieuthuc;
	
	cout << "Bieu thuc hau to tuong ung: " << chuyenhauto(bieuthuc) << endl;
	
	cout << "Gia tri: " << tinhHauTo(chuyenhauto(bieuthuc)) << endl;
	
}
