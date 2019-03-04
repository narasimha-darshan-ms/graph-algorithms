#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

typedef pair<int, int> iPair; 

class Graph 
{ 
	int V; 
	list< pair<int, int> > *adj; 

public: 
	Graph(int V); 
	void addEdge(int u, int v, int w); 

	void shortestPath(int src,int dest); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<iPair> [V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
} 

void Graph::shortestPath(int src,int dest) 
{ 
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	vector<int> dist(V, INF); 
	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	while (!pq.empty()) 
	{ 

		int u = pq.top().second; 
		pq.pop(); 

		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
 
			int v = (*i).first; 
			int weight = (*i).second; 

			if (dist[v] > dist[u] + weight) 
			{ 

				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	} 

		if(dist[dest] != INF)   cout<< dist[dest];
		else cout<<"-1";
} 

int main() 
{ 

int V,E,v1,v2,w;
    cin>>V>>E;
	Graph g(V);
	
 for(int i=0 ; i<E ; i++){
        cin>>v1>>v2>>w;
        g.addEdge(v1-1,v2-1,w); 
    }
    cin>>v1>>v2;
	g.shortestPath(v1-1 , v2-1); 
	return 0; 
} 
