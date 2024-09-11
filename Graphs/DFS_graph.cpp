#include<bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int,vector<int>> &adj, int u,vector<bool>&visited, vector<int> &result){

        if(visited[u]==true) return;

        visited[u]=true;
        result.push_back(u);
        for(int &v:adj[u]){
            if(!visited[v]){
                DFS(adj, v,visited,result);
            }
        }
}

// we can use this also ' '
vector<int> dfsGraph(int V, vector <int> mp[]){
    unordered_map<int,vector<int>>adj;

    for(int u=0;u<V;u++){
        for(auto v= mp[u].begin(); v!=mp[u].end();v++){
            adj[u].push_back(*v);
        }
    }

vector<int>result;
vector<bool> visited(V,false);

DFS(adj,0,visited,result);

return result;
}


int main(){
 
 int V =5;

vector<int> adj[] = {
        {2, 3, 1}, // neighbors of vertex 0
        {0},       // neighbors of vertex 1
        {0, 4},    // neighbors of vertex 2
        {0},       // neighbors of vertex 3
        {2}        // neighbors of vertex 4
    };

 vector<int> res;

 res=dfsGraph(V,adj);

  for (int u : res) {
        cout << u << " ";
    }

    return 0;
 }