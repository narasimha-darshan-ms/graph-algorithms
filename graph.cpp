#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool DFSUtil(int u,int v, vector<int> adj[], vector<bool> &visited) 
{ 
  
    if(u==v)    return true;
    visited[u-1] = true; 
    
    for (int i=0; i<adj[u-1].size(); i++) 
        if (visited[adj[u-1][i]-1] == false) {
            if(DFSUtil(adj[u-1][i],v, adj, visited))  return true;
        }
    return false;
} 

int main(){
    int V,E,v1,v2;
    cin>>V>>E;
    vector<int> AdjList[V];
    for(int i=0 ; i<E ; i++){
        cin>>v1>>v2;
        AdjList[v1-1].push_back(v2);
        AdjList[v2-1].push_back(v1);
    }
    
    cin>>v1>>v2;
    vector<bool> visited(V, false); 
    bool presence= DFSUtil(v1,v2, AdjList, visited);
    cout<<presence;
    return 0;
}