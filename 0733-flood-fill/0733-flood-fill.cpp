class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int newcolor, int oldcolor, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] == newcolor || image[i][j] != oldcolor) return;
        image[i][j] = newcolor;
        dfs(i + 1, j, image, newcolor, oldcolor, n, m);
        dfs(i - 1, j, image, newcolor, oldcolor, n, m);
        dfs(i, j + 1, image, newcolor, oldcolor, n, m);
        dfs(i, j - 1, image, newcolor, oldcolor, n, m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        dfs(sr, sc, image, color, image[sr][sc], n, m);
        return image;
    }
};