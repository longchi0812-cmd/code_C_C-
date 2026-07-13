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
			if (weight != INF && weight != 0)
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

//e
void DFS(AdjListGraph graph, int v, bool visited[])
{
    visited[v] = true;

    for (AdjList* p = graph.adjList[v]; p != NULL; p = p->next)
    {
        int u = p->adjVertex;
        if (!visited[u])
        {
            DFS(graph, u, visited);
        }
    }
}

bool isConnected(AdjListGraph graph)
{
    if (graph.numVertices == 0)
        return false;

    bool visited[MAX_VERTICES] = { false };

    DFS(graph, 0, visited);

    for (int i = 0; i < graph.numVertices; i++)
    {
        if (!visited[i])
            return false;
    }

    return true;
}

//f
void DFSConnectedComponents(AdjListGraph graph, int v, bool visited[], int component[], int k)
{
    visited[v] = true;
    component[v] = k;

    for (AdjList* p = graph.adjList[v]; p != NULL; p = p->next)
    {
        if (!visited[p->adjVertex])
        {
            DFSConnectedComponents(graph, p->adjVertex, visited, component, k);
        }
    }
}

int connectedComponents(AdjListGraph graph, int component[])
{
    bool visited[MAX_VERTICES] = { false };
    int k = 0;

    for (int i = 0; i < graph.numVertices; i++)
    {
        if (!visited[i])
        {
            k++;
            DFSConnectedComponents(graph, i, visited, component, k);
        }
    }

    return k;
}

//g
void printConnectedComponents(int component[], int n, int k)
{
    cout << "Num of connected components is: " << k << endl;

    for (int i = 1; i <= k; i++)
    {
        cout << "Component[" << i << "]: ";
        for (int j = 0; j < n; j++)
        {
            if (component[j] == i)
                cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
}

//i
void pathDFS(AdjListGraph graph, int s, int visited[], int parent[])
{
    visited[s] = 1;

    for (AdjList* p = graph.adjList[s]; p != NULL; p = p->next)
    {
        int v = p->adjVertex;
        if (!visited[v])
        {
            parent[v] = s;
            pathDFS(graph, v, visited, parent);
        }
    }
}


int main()
{
    AdjListGraph g5, g4;
    //a
    readGraphFromFile(g5, "Graph5.txt");
    
    readGraphFromFile(g4, "Graph4.txt");
    
    //b
    printGraph(g4);
    
    printGraph(g5);

    int parent[MAX_VERTICES];
    int s, d;

    cout << "Input start vertex: ";
    cin >> s;
    cout << "Input destination vertex: ";
    cin >> d;
    
	//c
    PathBFS(g4, s, parent);

	if (parent[d] == -1){
    	cout << "No path from " << s << " to " << d << endl;
	}else{
    	cout << "A path from " << s << " to " << d << " is: ";
    	printPath(parent, s, d);
    	cout << endl;
	}
	
	//i
	int visited[MAX_VERTICES] = {0};
	int parentDFS[MAX_VERTICES];

	for (int i = 0; i < g4.numVertices; i++)
    	parentDFS[i] = -1;

	parentDFS[s] = s;
	pathDFS(g4, s, visited, parentDFS);

	if (parentDFS[d] == -1)
	{
	    cout << "No path (DFS) from " << s << " to " << d << endl;
	}
	else
	{
	    cout << "A path (DFS) from " << s << " to " << d << " is: ";
	    printPath(parentDFS, s, d);
	    cout << endl;
	}


	//e
    bool connected = isConnected(g5);
    if (connected)
        cout << "Graph is connected." << endl;
    else
        cout << "Graph is unconnected." << endl;
	
	//f
    int comp[MAX_VERTICES] = { -1 };
    int k = connectedComponents(g5, comp);
    //g
    printConnectedComponents(comp, g5.numVertices, k);

    return 0;
}

