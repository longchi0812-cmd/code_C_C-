#include<bits/stdc++.h>

using namespace std;

#define MAX_VERTICES 100

struct AdjMatrixGraph{
	int numVertices;
	int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void inputGraph(AdjMatrixGraph &graph){
	graph.numVertices = 7;
	int temp[7][7] = {
		{0, 1, 1, 0, 0, 1, 0},
		{1, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 1},
		{0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0}
	};
	for(int i = 0; i < graph.numVertices; i++)
		for(int j = 0; j < graph.numVertices; j++)
			graph.adjMatrix[i][j] = temp[i][j];
}

void DFS(const AdjMatrixGraph& graph, int vertex, bool visited[]){
	visited[vertex] = true;
	cout << vertex << " ";
	for(int i = 0; i < graph.numVertices; i++)
		if(graph.adjMatrix[vertex][i] != 0 && !visited[i])
			DFS(graph, i, visited);
}

//d
void cumKetNoi(const AdjMatrixGraph& graph){
	bool visited[MAX_VERTICES];
	memset(visited, false, sizeof(visited));
	int count = 0;
	for(int i = 0; i < graph.numVertices; i++){
		if(!visited[i]){
			count++;
			cout << "Cum " << count << ": ";
			DFS(graph, i, visited);
			cout << endl;
		}
	}
	cout << "So cum ket noi: " << count << endl;
}

//a
void demTram(AdjMatrixGraph g, int k){
	int count = 0;
	for(int i = 2; i < g.numVertices ; i++)
		if(g.adjMatrix[k][i] == 0){
			count++;
			cout <<" "<<count;
		}
}




int main(){
	AdjMatrixGraph g;
	inputGraph(g);
	
	
	//d
	cumKetNoi(g);
	
	//a
	cout << "Tram sac thu 1 khong ket voi: ";
	demTram(g, 1);
	
    return 0;
}

