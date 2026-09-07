class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;
        for(int j = 0;j < isConnected[node].size();j++) {
            if(isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> vis(n, 0);
        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i, isConnected, vis);
                count++;
            }
        }
        return count;
    }
};