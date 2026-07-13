#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long dem = 0;
//    long long dau = 1;
//
//    for(long long i = 1; ; i++){
//        long long cuoi = dau * 10 - 1;
//
//        if(dau > n) break;
//
//        long long count = min(n, cuoi) - dau + 1;
//        dem += count * i;
//
//        dau *= 10;
//    }

	for(long long i = 1; i <= n; i++){
	    long long x = i;
	    while(x > 0){
	        dem++;
	        x /= 10;
	    }
	}
    cout << dem;
}
