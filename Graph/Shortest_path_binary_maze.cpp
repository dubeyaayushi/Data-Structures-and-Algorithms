/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
           int n = grid.size();
            //edge case yehoga guyssssssssssssssssssss
              if (grid[0][0] == 1 || grid[n-1][n-1] == 1) 
                return -1;
             if(n == 1) 
             return 1;
             vector<vector<int>> dist(n, vector<int>(n , 1e9)); 
             //to understand it better this is the syntax we can keep in our mind vector<Type> vec(size, initial_value);
             //here i have created a dist 2D array to keep the track of the distance covered in the binary maze
              
             dist[0][0] = 1;
                 queue<pair<int , pair<int , int>>>q;
             q.push({1,{0,0}});
             int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};// use to move all directions in r also we are moving diagonally here as well
            int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};// use to movee all directions in c diagonaly bhi chal rhe hai idhar
             while(!q.empty()){
                auto it = q.front();
                q.pop();
                int dis = it.first;//shortest dis associcagted with that node
                int r = it.second.first;// retrive the co-ordinates of row from it;
                int c = it.second.second; // retrive the co-rordinates of column from it;
                for(int i = 0; i<8 ; i++){
                    int newr = r + dr[i];
                    int newc = c + dc[i];
        if(newr >= 0 && newr < n && newc >=0 && newc <n && grid[newr][newc] == 0 && dis+1 < dist[newr][newc]){
            dist[newr][newc] = 1+dis;
            if(newr == n-1 && newc == n-1)
                return dis+1;
                q.push({dis+1 , {newr, newc}});
        
            }
              }
             
                 }
                  return -1; //if no path found
        }
    };