#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	stringstream ss(s);
	string res = "", word;
	while(ss >> word){
		res += toupper(word[0]);
		for(int i = 1; i < word.size(); i++){
			res += tolower(word[i]);
		}
		res += " ";
	}
	res.pop_back();
	cout << res << endl;
}
