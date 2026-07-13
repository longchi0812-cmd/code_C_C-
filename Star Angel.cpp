//#include <iostream>
//using namespace std;
//
//void hanoi(int n, int from, int temp, int to) {
//    if (n == 1) {
//        cout << from << " " << to << endl;
//        return;
//    }
//
//    hanoi(n - 1, from, to, temp);
//    cout << from << " " << to << endl;
//    hanoi(n - 1, temp, from, to);
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    cout << (1 << n) - 1 << endl;
//
//    hanoi(n, 1, 2, 3);
//
//    return 0;
//}
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    for (long long k = 1; k <= n; k++) {
        long long total = k * k * (k * k - 1) / 2;
        long long attack = 4 * (k - 1) * (k - 2);

        cout << total - attack << endl;
    }

    return 0;
}
