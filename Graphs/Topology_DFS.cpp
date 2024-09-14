#include<bits/stdc++.h>
using namespace std;

void TopologyDFS(vector<int> adj[],int u, vector<bool>&visited, stack<int> &stk){

    visited[u]=true;

    for(auto &v:adj[u]){
        if(!visited[v]){
            TopologyDFS(adj,v,visited,stk);
        }
    }
        stk.push(u);
}

vector<int> Topology_sorting(int V, vector<int> adj[]){
    vector<bool> visited(V,false);
     stack<int>stk;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            TopologyDFS(adj,i,visited,stk);
        }
    }

    vector<int> result;

    while(!stk.empty()){
        result.push_back(stk.top());
        stk.pop();
    }

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

 res=Topology_sorting(V,adj);

  for (int u : res) {
        cout << u << " ";
    }

return 0;
 }