/*You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 */

 #include<bits/stdc++.h>
 using namespace std;


 class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n = heights.size();//get size of rows
            int m = heights[0].size();//get size of columns
            priority_queue<pair<int, pair<int , int>>, //this will hold the distance and the co-ordinates of the row and column 
            vector<pair<int , pair<int , int>>>, // it acts as an container to store the elements 
            greater<pair<int , pair<int, int>>>> // our priority queue acts as a max heap therefore it stores the largest element at the top hence we use greater<> in order to modify it as min heap aand let it store the min element at the top.. :-(niceeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee)) :-)
            pq;
            vector<vector<int>> dist(n , vector<int>(m,1e9));
            dist[0][0] = 0;
            pq.push({0, {0,0}});
            int dr[] = {-1 , 0 , 1, 0};
            int dc[] = {0 , 1, 0 , -1};
    
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int diff = it.first;
                int row = it.second.first;
                int col = it.second.second;
                if(row == n-1 && col == m-1)
                return diff;
                for(int i =0 ; i<4 ; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(newr >= 0 && newc >= 0 && newr< n&& newc <m){
                        int newEff = max(abs(heights[row][col]- heights[newr][newc]) , diff); //new and old dis comparison done
                        if (newEff < dist[newr][newc]){
                            dist[newr][newc] = newEff;
                            pq.push({newEff , {newr, newc}});
                        }
                    }
                }
            }
             return 0;
        }
    };