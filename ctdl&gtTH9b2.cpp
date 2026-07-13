#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 100

struct Graph {
    int n;
    int a[MAX][MAX];
};

void readGraph(string fn, Graph &g) {
    ifstream f(fn);
    f >> g.n;
    for (int i = 0; i < g.n; i++)
        for (int j = 0; j < g.n; j++)
            f >> g.a[i][j];
    f.close();
}

void printGraph(Graph g) {
    cout << "So dinh = " << g.n << "\n";
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++)
            cout << g.a[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

//a
bool knowsDirect(Graph g, int x, int y) {
    return g.a[x][y] == 1;
}

//b
bool knowsIndirect(Graph g, int x, int z) {
    bool visited[MAX] = {false};
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == z) return true;

        for (int v = 0; v < g.n; v++)
            if (g.a[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }
    return false;
}

//c
bool knowsAll(Graph g, int x) {
    for (int i = 0; i < g.n; i++)
        if (!knowsIndirect(g, x, i))
            return false;
    return true;
}

//d
void nobodyKnows(Graph g) {
    cout << "Nhung sinh vien khong ai biet: ";
    for (int j = 0; j < g.n; j++) {
        bool ok = false;
        for (int i = 0; i < g.n; i++)
            if (g.a[i][j] == 1) ok = true;
        if (!ok) cout << j << " ";
    }
    cout << "\n";
}

//e
void listKnowAll(Graph g) {
    cout << "Sinh vien biet het ca lop: ";
    for (int i = 0; i < g.n; i++)
        if (knowsAll(g, i)) cout << i << " ";
    cout << "\n";
}

int main() {
    Graph g;
    readGraph("GraphPhone.txt", g);

    cout << "==== DO THI SDT DIEN THOAI ====\n";
    printGraph(g);

    int x = 0, y = 2, z = 4;
    
    cout << "a) ";
	if(knowsDirect(g, x, y)){
    	cout << x << " biet truc tiep sdt " << y << endl;
	} else {
		cout << x << " khong biet truc tiep sdt " << y << endl;
	}
	
    cout << "b) ";
    if(knowsIndirect(g, x, z)){
    	cout << x << " biet truc tiep/gian tiep sdt " << z << endl;
	} else {
		cout << x << " khong biet truc tiep/gian tiep sdt " << z << endl;
	}

    cout << "c) ";
    if(knowsAll(g, x)){
    	cout << x << " biet het sdt ca lop " << endl;
	} else {
		cout << x << " khong biet het sdt ca lop " << endl;
	}

    cout << "d) ";
    nobodyKnows(g);

    cout << "e) ";
    listKnowAll(g);

    return 0;
}

