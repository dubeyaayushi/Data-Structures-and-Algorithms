/* Given a graph of V vertices numbered from 0 to V-1. Find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n x n. Matrix[i][j] denotes the weight of the edge from i to j. If matrix[i][j]=-1, it means there is no edge from i to j.


Examples:
Input: matrix = [[0, 2, -1, -1],[1, 0, 3, -1],[-1, -1, 0, 1],[3, 5, 4, 0]]

Output: [[0, 2, 5, 6], [1, 0, 3, 4], [4, 6, 0, 1], [3, 5, 4, 0]] 

Explanation: matrix[0][0] is storing the distance from vertex 0 to vertex 0, the distance from vertex 0 to vertex 1 is 2 and so on.

Input: matrix = [[0,25],[-1,0]]

Output: [[0, 25],[-1, 0]]

Explanation: The matrix already contains the shortest distance. */

#include<bits/stdc++.h> 
using namespace std;

class Solution {
    public:
        void shortestDistance(vector<vector<int>>&matrix) {
         
         int n = matrix.size();
    
         for(int i =0; i<n ; i++){
            for(int j =0 ; j<n ; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if(i == j)
                matrix[i][j] =0;
            }
         }
         for(int k =0 ; k<n; k++){
            for(int i =0 ; i<n ; i++){
                for(int j =0 ; j<n ; j++){
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k]+matrix[k][j]);
    
                }
            }
         }
    
        for(int i =0 ; i<n ; i++){
            for(int j = 0; j<n ; j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] =-1;
                }
            }
        }
    
        }
    };

    int main() {

        int V = 4;
        vector<vector<int>> matrix(V, vector<int>(V, -1));
        matrix[0][1] = 2;
        matrix[1][0] = 1;
        matrix[1][2] = 3;
        matrix[3][0] = 3;
        matrix[3][1] = 5;
        matrix[3][2] = 4;
    
        Solution obj;
        obj.shortestDistance(matrix);
    
        for (auto row : matrix) {
            for (auto cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    
        return 0;
    }