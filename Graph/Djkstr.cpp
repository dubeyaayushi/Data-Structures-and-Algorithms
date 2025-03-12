/*Dijkstra Algorithm
Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.
Note: The Graph doesn't contain any negative weight edge.*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        set<pair<int , int>> st;
        vector<int> dist(V , 1e9);
        st.insert({0,src});//source can be any node i..e..src
        dist[src] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
    int node = it.second; /*The second element (it.second) represents the node itself.*/
int dis = it.first;/*The first element (it.first) represents the shortest known distance to a node.*/
         st.erase(it);
            
            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adj[node]){
                int adjNode = it.first; // ✅ Extracts the adjacent node
                int edgw = it.second;  // ✅ Extracts the edge weight
                if(dis+edgw < dist[adjNode]){ 
                  // erase if it was visited previously at 
                    // a greater cost.
                    if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});
                      // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgw;
                    st.insert({dist[adjNode], adjNode});
                }
            }
            
        }
        return dist;
    }
};

