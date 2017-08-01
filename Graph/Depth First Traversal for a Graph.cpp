#include<bits/stdc++.h>
using namespace std;
 
class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void DFS1(int s);
		void DFS2();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}


void Graph::DFSUtil(int s,bool visited[])
{
	visited[s] = true;
	cout<<s<<" ";
	list<int>::iterator i;
	for(i = adj[s].begin();i!=adj[s].end();i++)
	{
		if(!visited[*i])
			DFSUtil(*i,visited);
	}
}

void Graph::DFS1(int s)
{
	bool *visited = new bool[V];
	for(int i = 0;i < V;i++)
	{
		visited[i] = false;
	}
	DFSUtil(s,visited);
}

void Graph::DFS2()		//for diconneccted graph
{
	bool *visited = new bool[V];
	for(int i = 0;i < V;i++)
	{
		visited[i] = false;
	}
	for(int i = 0;i<V;i++)
	{
		if(!visited[i])
		{
			DFSUtil(i,visited);
		}
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS1(2);
    cout<<endl;
    g.DFS2();
}
