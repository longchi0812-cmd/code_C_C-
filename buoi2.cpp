//#include <bits/stdc++.h>
//using namespace std;
//
//#define ll long long
//
//int main(){
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//
//	vector <pair<ll, ll>> b(3);
//	for(auto &x:b){
//		cin >> x.first >> x.second;
//	}
//	
//	sort(b.begin(), b.end(), greater<pair<ll, ll>>());
//	for(auto &x:b){
//	
//		cout << x.first << " " << x.second;
//	}
//}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);
	
	ll n, s;
	
	cin >> n >> s;
	
	ll a[n], t = 0, re = n + 1;
	
	for(ll i = 0; i< n;i ++){
		cin >> a[i];
	}
	
	ll j = 0;
	for(ll i = 0; i < n; i++){
		t += a[i];
		while(t >= s){
			re = min(re, i - j + 1);
			t -= a[j];
			j++;
		}
	}
	
	if(re == n + 1){
		cout << 0;
	}else{
		cout << re;
	}
}
//
//    sort(a, a + n, greater<int>()); // s?p x?p tang d?n
//
//    for(int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//   }
	
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    vector<int> v = {5, 2, 9, 1, 3};
//
//    sort(v.begin(), v.end());
//
//    for(int x : v) cout << x << " ";
//}
//	#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    vector<pair<int,int>> v;
//
//    v.push_back({2, 3});
//    v.push_back({1, 5});
//    v.push_back({2, 1});
//
//    sort(v.begin(), v.end());
//
//    for(auto p : v) {
//        cout << p.first << " " << p.second << endl;
//    }
//}
//	Ghi nh? nhanh:
//	sort(a, a+n) ? tang d?n
//	sort(a, a+n, greater<int>())
	///////F
//	int n, W;
//    cin >> n >> W;
//
//    vector<int> dp(W + 1, 0);
//
//    for(int i = 0; i < n; i++){
//        int w, v;
//        cin >> w >> v;
//
//        for(int j = W; j >= w; j--){
//            dp[j] = max(dp[j], dp[j - w] + v);
//        }
//    }
//
//    cout << dp[W];
	
//}
//	vector <int> b;///vector rong
//	vector <int> a(10);/// vector 10 phan tu [0....9]///a(spt, gt)h
//	for(int i = 0; i< 10; i++){ cout << a[i] << ' '; }
//	vector <int> :: iterator it;
//	for(it = a.begin(); it != a.end(); it++)
//		cout << *it;
//	for(auto x:a){ //auto tu dong ep kieu dl
//		cout << x << ' ';
//	}
//	for(int i = 0; i < 10; i++) a[i] = i;
//	cout << a.size();
//	cout << a.front(); //pt dau
	//cout << a.back(); //pt cuoi
	//cout << a[a.size() - 1];
	//cout << b.empty();
	///if(b.size()) cout << b[0];
	///a.erase(a.begin() + 2, a.begin() + 6);
	
	///a.pop_back();
	///for(int x:a) cout << x << ' ';
	//swap(a, b);
//	a.push_back(100);
//	for(int x:a) cout << x << ' ';
