#include<bits/stdc++.h>
using namespace std;

bool isCycleDFS(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &inRecursion){
    visited[u]=true;
    inRecursion[u]=true;

    for(auto &v:adj[u]){
        if(visited[v]==false && isCycleDFS(adj,v,visited,inRecursion)) return true;

        if(inRecursion[v]==true) return true;
    }
    return false;
}


bool isCycle(int V, vector<int> adj[]){

    vector<bool> visited(V,false);
    vector<bool> inRecursion(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)) return true;
    }
    return false;
}

int main(){


int V =5;

vector<int> adj[] = {
        {1},
        {0,2,4},
        {1,3},
        {2,4},
        {1,3}
    };

bool res;

 res=isCycle(V,adj);

cout<<res;

return 0;
 }