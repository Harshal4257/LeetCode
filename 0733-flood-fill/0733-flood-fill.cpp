class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int newc, int oldc){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] == newc || image[i][j] != oldc) return;
        image[i][j] = newc;
        dfs(i + 1, j, image, newc, oldc);
        dfs(i - 1, j, image, newc, oldc);
        dfs(i, j + 1, image, newc, oldc);
        dfs(i, j - 1, image, newc, oldc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr, sc, image, color, image[sr][sc]);
        return image;
    }
};