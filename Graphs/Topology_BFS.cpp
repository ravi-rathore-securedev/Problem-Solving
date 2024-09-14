#include<bits/stdc++.h>
using namespace std;

vector<int> Topology_sorting(int V, vector<int> adj[]){
    vector<int> indegree(V,0);
    queue<int> q;

    for(int u=0;u<V;u++){
        for(auto &v:adj[u]){
            indegree[u]++;
        }
    }

    for(int i=0;i<V;i++){
        if(indegree[i]==0)
        q.push(i);
    }

    vector<int> result;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        result.push_back(u);
        for(auto &v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
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