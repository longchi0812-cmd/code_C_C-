#include<iostream>
using namespace std;

int main(){
	int m, n, x, y;
	cin >> n;
	cin >> m;
	int a[n];
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int maxx;
	for(int j = 1; j <= m; j++){
		cin >> x >> y;
		maxx = a[x];
		for (int k = x+1; k <= y; k++)
			maxx = max(maxx, a[k]);
		cout << maxx << "\n";
	}
}
