#include <vector>
#include <queue>

using namespace std;

class Solution {
public:  
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        int n = grid.size();
        int m = grid[0].size();
        
        // Direction arrays for traveling Up, Right, Down, Left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        // FIX 1: Loop while the queue is not empty
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse all 4 neighbors
            for(int k = 0; k < 4; k++) {
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];
                
                // FIX 2: Ensure ncol is checked against 'm'
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol}); 
                }
            }
        }
    }
      
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};