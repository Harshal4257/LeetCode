class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int& count) {
        if(i < 0 ||j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 1) {
            return;
        }
        vis[i][j] = 1;
        count++;
        dfs(i + 1, j, grid, vis, n, m, count);
        dfs(i - 1, j, grid, vis, n, m, count); 
        dfs(i, j - 1, grid, vis, n, m, count); 
        dfs(i, j + 1, grid, vis, n, m, count); 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxx = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0 ;i < n ;i++) {
            for(int j = 0;j < m;j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, grid, vis, n, m, count);
                    maxx = max(maxx, count);
                }
            }
        }
        return maxx;
    }
};