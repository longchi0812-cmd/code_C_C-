#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#define MAX_VERTICES 100
#define INF 1000 //infinity

struct AdjList
{
	int adjVertex;
	float weight;
	AdjList* next;
};

struct AdjListGraph
{
	int numVertices;
	AdjList* adjList[MAX_VERTICES];
};

//a
void readGraphFromFile(AdjListGraph& graph, string fileName)
{
	ifstream file(fileName);
	file >> graph.numVertices;
	
	for (int i = 0; i < graph.numVertices; i++)
	{
	graph.adjList[i] = nullptr;
		for (int j = 0; j < graph.numVertices; j++)
		{
			float weight;
			file >> weight;
			if (weight != INF)
			{
				AdjList* newNode = new AdjList;
				newNode->adjVertex = j;
				newNode->weight = weight;
				newNode->next = graph.adjList[i];
				graph.adjList[i] = newNode;
			}
		}
	}
	file.close();
}

//b 
void printGraph(AdjListGraph graph)
{
	cout << "Num of vertices: " << graph.numVertices << endl;
	for (int i = 0; i < graph.numVertices; i++)
	{
		cout << "adjList[" << i << "]: ";
		for (AdjList* p = graph.adjList[i]; p != nullptr; p = p->next)
		{
			cout << p->adjVertex << "(" << p->weight << ") ";
		}
		cout << endl;
	}
	cout << endl;
}

//c
void PathBFS(AdjListGraph graph, int s, int parent[])
{
	bool visited[MAX_VERTICES] = { false };
	
	for(int i = 0; i<graph.numVertices; i++) parent[i] = -1;
	queue<int> q;
	visited[s] = true;
	parent[s] = s;
	q.push(s);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (AdjList* p = graph.adjList[curr]; p!= nullptr; p=p->next)
		{
			if (!visited[p->adjVertex])
			{
				visited[p->adjVertex] = true;
				parent[p->adjVertex] = curr;
				q.push(p->adjVertex);
			}
		}
	}
}

//d
void printPath(int parent[],int s, int v)
{
	if (v == s)
	{
		cout << s << " ";
		return;
	}
	printPath(parent, s, parent[v]);
	cout << v << " ";
}


int main()
{
	AdjListGraph g;
	readGraphFromFile(g, "Graph5.txt");
	printGraph(g);
	
	int parent[MAX_VERTICES];
	int s, d;
	cout << "Input start vertex: "; cin >> s;
	cout << "Input destination vertex: "; cin >> d;
	PathBFS(g, s, parent);
	
	if(parent[d] == -1){
    	cout << "No path from " << s << " to " << d << endl;
	}else{
    	cout << "A path from " << s << " to " << d << " is: ";
    	printPath(parent, s, d);
    	cout << endl;
	}

	return 0;
}
