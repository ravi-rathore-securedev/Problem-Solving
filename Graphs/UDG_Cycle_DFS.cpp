#include<bits/stdc++.h>
using namespace std;

bool CycleDFS(unordered_map<int,vector<int>> &adj, int u, vector<bool>& visited, int parent){

    visited[u]=true;

    for(auto &v:adj[u]){
        if(v==parent) continue;

        if(visited[v]==true) return true;

        if( CycleDFS(adj,v,visited,u)) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> mp[]){

    unordered_map<int,vector<int>> adj;

    for(int u=0;u<V;u++){
        for(auto v=mp[u].begin();v!=mp[u].end();v++){
            adj[u].push_back(*v);
        }
    }

    vector<bool> visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i] && CycleDFS(adj,i,visited,-1)){
            return true;
        }
    }
    return false;
}


int main(){

 int V =5;

vector<int> adj[] = {
        {1}, // neighbors of vertex 0
        {0,2,4},       // neighbors of vertex 1
        {1,3},    // neighbors of vertex 2
        {2,4},
        {1,3}       // neighbors of vertex 3
    };

bool res;

 res=isCycle(V,adj);

cout<<res;

return 0;
 }
