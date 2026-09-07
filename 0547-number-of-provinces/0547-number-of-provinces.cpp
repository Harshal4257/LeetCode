class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

/* class Solution {
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
*/