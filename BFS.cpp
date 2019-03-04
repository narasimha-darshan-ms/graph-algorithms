
#include<iostream> 
#include <list> 
#include<vector>

using namespace std; 

class Graph 
{ 
	int V; 
	list<int> *adj;

public: 
	vector<int> depth;
	Graph(int V);
	void addEdge(int v, int w); 
	void BFS(int s); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V];
	for(int i=0;i<V;i++)
	    depth.push_back(-1);
} 

void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
    adj[w].push_back(v);
} 

void Graph::BFS(int s) 
{ 

	bool *visited = new bool[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	list<int> queue; 

	visited[s] = true; 
	depth[s] = 0;
	queue.push_back(s); 
	list<int>::iterator i; 

	while(!queue.empty()) 
	{ 
		s = queue.front(); 
		queue.pop_front(); 
		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{ 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				depth[*i] = depth[s]+1;
				queue.push_back(*i); 
			} 
		} 
	} 
} 

int main() 
{ 
	int V,E,v1,v2;
    cin>>V>>E;
	Graph g(V);
	
 for(int i=0 ; i<E ; i++){
        cin>>v1>>v2;
        g.addEdge(v1-1,v2-1); 
    }
    cin>>v1>>v2;
	g.BFS(v1-1); 
    cout<<g.depth[v2-1];
	return 0; 
} 
