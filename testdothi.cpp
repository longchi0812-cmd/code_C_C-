#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX_VERTICES 100

struct AdjList {
    int adjVertex;     // d?nh k?
    float weight;      // tr?ng s? (không dùng cung d? dó)
    AdjList* next;
};

struct AdjListGraph {
    int numVertices;                 // s? sinh viên
    AdjList* adjList[MAX_VERTICES];  // danh sách k?
};

void initGraph(AdjListGraph &g, int n) {
    g.numVertices = n;
    for (int i = 0; i < n; i++)
        g.adjList[i] = NULL;
}

void addEdge(AdjListGraph &g, int u, int v) {
    // u -> v
    AdjList* node = new AdjList{v, 1.0, g.adjList[u]};
    g.adjList[u] = node;

    // v -> u
    node = new AdjList{u, 1.0, g.adjList[v]};
    g.adjList[v] = node;
}

void DFS(AdjListGraph &g, int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";

    for (AdjList* p = g.adjList[u]; p != NULL; p = p->next) {
        int v = p->adjVertex;
        if (!visited[v])
            DFS(g, v, visited);
    }
}


void BFS(AdjListGraph &g, int start) {
    bool visited[MAX_VERTICES] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (AdjList* p = g.adjList[u]; p != NULL; p = p->next) {
            int v = p->adjVertex;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void sinhVienCungTinh(AdjListGraph &g, int k) {
    bool visited[MAX_VERTICES] = {false};
    DFS(g, k, visited);
}

void thanhPhanLienThong(AdjListGraph &g) {
    bool visited[MAX_VERTICES] = {false};
    int soTinh = 0;

    for (int i = 0; i < g.numVertices; i++) {
        if (!visited[i]) {
            soTinh++;
            cout << "Tinh " << soTinh << ": ";
            DFS(g, i, visited);
            cout << endl;
        }
    }

    cout << "So tinh trong lop: " << soTinh << endl;
}

void printGraph(AdjListGraph &g) {
    for (int i = 0; i < g.numVertices; i++) {
        cout << i << ": ";
        AdjList* p = g.adjList[i];
        while (p != NULL) {
            cout << p->adjVertex << " ";
            p = p->next;
        }
        cout << endl;
    }
}


int main() {
    AdjListGraph g;

    // Gi? s? l?p có 6 sinh viên: 0 ? 5
    initGraph(g, 6);

    // Các c?p sinh viên cùng t?nh
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
    
    cout << "Danh sach ke cua do thi:\n";
	printGraph(g);

    cout << "Sinh vien cung tinh voi sinh vien 0: ";
	bool visited[MAX_VERTICES] = {false};
    DFS(g, 0, visited);

    cout << "\nThong tin cac tinh trong lop:\n";
    thanhPhanLienThong(g);

    return 0;
}


