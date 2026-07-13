#include <iostream>
using namespace std;
int main(){
	int N, M;
	int a[100], b[100], c[100];
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int k, l, r;
		cin >> k >> l >> r;
		
		if(k == 0){
			a[l] += 1;
			a[r+1] -= 1;
		}
		else if(k == 1){
			a[l] -= 1;
			a[r+1] += 1;
		}
		else if(k == 2){
			b[l] += 1;
			b[r+1] -= 1;
			c[l] += (1-l);
			c[r+1] -= (1 - l);
		}
		else if(k ==3){
			b[l] -= 1;
			b[r +1] += 1;
			c[l] += (r + 1);
			c[r+1] -= (r + 1);
		}
	}
	int ka = 0, kb = 0, kc = 0;
	for(int i = 1; i <= N; i++){
		ka += a[i];
		kb += b[i];
		kc += c[i];
		int k = ka + kb * i + kc;
		cout << k << " ";
	}
	cout << "\n";
}

