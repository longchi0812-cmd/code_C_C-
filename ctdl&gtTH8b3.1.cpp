#include <iostream>
#include <queue>

using namespace std;

struct Sosanhchanle {
    bool operator()(int a, int b) {
        if (a % 2 != 0 && b % 2 == 0) return true;
        
        if (a % 2 == 0 && b % 2 != 0) return false;
        
        return a < b;
    }
};

int main()
{
    int arr[6] = {10, 2, 4, 8, 6, 9};
    //a
	//priority_queue<int, vector<int>, greater<int> > pq;
	//b
    priority_queue<int, vector<int>, Sosanhchanle > pq;
    
    cout << "Array: ";
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    for (int i = 0; i < 6; i++) {
        pq.push(arr[i]);
    }

    cout << "Priority Queue (tang dan): ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}

