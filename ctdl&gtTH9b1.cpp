#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX_VERTICES 100

struct AdjMatrixGraph
{
    int numVertices;// so dinh
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];// ma tran ke cu do thi
};

//a
void readGraphFromFile(string fileName, AdjMatrixGraph &graph)
{
    ifstream file(fileName);
    file >> graph.numVertices;

    for (int i = 0; i < graph.numVertices; i++)
        for (int j = 0; j < graph.numVertices; j++)
            file >> graph.adjMatrix[i][j];

    file.close();
}

//b
void printGraph(AdjMatrixGraph graph)
{
    cout << "Num of vertices: " << graph.numVertices << endl;
    for (int i = 0; i < graph.numVertices; i++)
    {
        for (int j = 0; j < graph.numVertices; j++)
            cout << graph.adjMatrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

//c
void DFS(const AdjMatrixGraph& graph, int vertex, bool visited[])
{// DFS duyet theo chieu sau
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < graph.numVertices; i++)
        if (graph.adjMatrix[vertex][i] != 0 && !visited[i])
            DFS(graph, i, visited);
}

//d
void DFS_d(const AdjMatrixGraph& graph, int vertex, bool visited[])
{
    visited[vertex] = true;
    for (int i = 0; i < graph.numVertices; i++)
        if (graph.adjMatrix[vertex][i] != 0 && !visited[i])
            DFS_d(graph, i, visited);
}

//e
void traverseGraph(AdjMatrixGraph g)
{
    bool visited[MAX_VERTICES];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < g.numVertices; i++)
    {
        if (!visited[i])
        {
            cout << "Thanh phan lien thong bat dau tu dinh " << i << ": ";
            DFS(g, i, visited);
            cout << endl;
        }
    }
}

//f
void BFS(const AdjMatrixGraph& graph, int vertex)
{
    queue<int> q;
    bool visited[MAX_VERTICES];
	memset(visited, false, sizeof(visited));

    visited[vertex] = true;
    q.push(vertex);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int i = 0; i < graph.numVertices; i++)
        {
            if (graph.adjMatrix[curr][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

//g
int countEdges(AdjMatrixGraph g)
{
    int count = 0;
    for (int i = 0; i < g.numVertices; i++)
        for (int j = i + 1; j < g.numVertices; j++)
            if (g.adjMatrix[i][j] != 0)
                count++;

    return count;
}

//h
int countIncomingEdges(AdjMatrixGraph g, int x)
{
	int count = 0;
	for(int i = 0; i < g.numVertices; i++){
		if(g.adjMatrix[i][x] != 0){
			count++;
		}
	}
	return count;
}

//i
void notAdjacent(AdjMatrixGraph g, int x)
{
	for(int i = 0; i < g.numVertices; i++){
		if(g.adjMatrix[i][x] == 0 && g.adjMatrix[x][i] == 0 && i != x){
			cout << i << " ";
		}
	}

}

//j
void notVisited(AdjMatrixGraph g, int x)
{
	bool visited[MAX_VERTICES];
	memset(visited, false, sizeof(visited));
	
	DFS_d(g, x, visited);
	
	for(int i = 0; i < g.numVertices; i++){
		if(!visited[i]){
			cout << i << " ";
		}
	}
}

//k
bool isPath(AdjMatrixGraph g, int arr[], int k)
{
	if (k < 2) return false;
    for (int i = 0; i < k - 1; i++) {
        if (g.adjMatrix[arr[i]][arr[i+1]] == 0) {
            return false;
        }
    }
    return true;
}

//l
void pathToVertex(AdjMatrixGraph g, int x)
{
	bool visited[MAX_VERTICES];
    memset(visited, false, sizeof(visited));

    queue<int> q;

    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < g.numVertices; u++) {
            if (g.adjMatrix[u][v] != 0 && !visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    cout << "Cac dinh den duoc dinh " << x << ": ";
    for (int i = 0; i < g.numVertices; i++) {
        if (i != x && visited[i]) {
            cout << i << " ";
        }
    }
}

int main()
{
    AdjMatrixGraph g;

    cout << "==== DOC DO THI TRONG SO Graph2.txt ====" << endl;
    
    bool visited[MAX_VERTICES];
    memset(visited, false, sizeof(visited));
    readGraphFromFile("Graph2.txt", g);
    printGraph(g);
    
    //c
    cout << "DFS tu dinh 0: ";
    DFS(g, 0, visited);
    cout << "\n\n";
    
    //f
    cout << "BFS tu dinh 0: ";
    BFS(g, 0);
    cout << "\n\n";

	//g
    cout << "Tong so canh cua do thi vo huong: " << countEdges(g);
    cout << "\n\n";
    
    //h
    //cout << "Tong so canh cua do thi co huong: " << countIncomingEdges(g, 2) << endl;
    
    //i
    cout << "Nhung dinh khong ke voi dinh X: ";
    notAdjacent(g, 2);
    cout << "\n\n";
    
    //j
    cout << "Cac dinh khong tham duoc: ";
    notVisited(g, 2);
    cout << "\n\n";
    
    //k
    int arr[] = {0, 1, 2};
    if(isPath(g, arr, 3)){
    	cout << "Day cac dinh la duong di cua do thi." << endl;
	} else {
		cout << "Day cac dinh khong la duong di cua do thi." << endl;
	}
	
	//l
	//pathToVertex(g, 2);
    
    return 0;
}
