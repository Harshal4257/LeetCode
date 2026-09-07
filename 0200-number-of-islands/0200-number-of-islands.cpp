class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1') {
            return;
        }
        vis[i][j] =  1;
        dfs(i - 1, j, grid, vis, n, m);
        dfs(i, j - 1, grid, vis, n, m);
        dfs(i + 1, j, grid, vis, n, m);
        dfs(i, j + 1, grid, vis, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
