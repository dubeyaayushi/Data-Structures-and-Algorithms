#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n ; i++){
            parent[i] =i;
        }
    }
    int findUpar(int node){
        if(node == parent[node])
        return node;
         return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }
};

class solution {
    public: 
    int spanningTree(int V, vector<vector<int>> adj[]){
        /* adj[]: Adjacency list of the graph where each entry is a list of {neighbour, weight} pairs.*/
        vector<pair<int, pair<int , int>>> edges;/*Create Edge List*/
        for(int i =0 ; i<V ; i++){
            for( auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt , {node , adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin() , edges.end());
        int mstWt = 0;
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUpar(u) != ds.findUpar(v)){
                mstWt += wt;
                ds.unionByRank(u, v);
            }

        }
        return mstWt;
    }
};

int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}

