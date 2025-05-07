/*  Number of Ways to Arrive at Destination
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Adjacency list for the graph
        vector<vector<pair<int, int>>> adj(n);

        // Building the graph
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Priority Queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // Distance array initialized to a large value
        vector<long long> dist(n, LLONG_MAX);

        // Ways array to store the number of ways to reach each node
        vector<int> ways(n, 0);

        // Initialize the start node
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Modulo value to avoid overflow
        int mod = (int)(1e9 + 7);

        // Dijkstra's algorithm to find shortest paths
        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Explore adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                long long newDist = dis + edw;

                // If a shorter distance is found
                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                    ways[adjNode] = ways[node]; // Update number of ways
                }
                // If same distance is found, add the number of ways
                else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        // Return the number of ways to reach the last node
        return ways[n - 1] % mod;
    }
};


int main()
{
    // Driver Code.
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.countPaths(n, edges);

    cout << ans;
    cout << endl;

    return 0;
}