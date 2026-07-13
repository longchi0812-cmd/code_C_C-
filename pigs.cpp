#include <iostream>
using namespace std;

int main(){
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	int a = ((n1 + 1) * (n2 + 1));
	int b = (m + 1);
	float N =(((float)a/b) - 1);
	N = (int)N;
	cout << N;
	
}
