class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& recpath, vector<vector<int>>& edges) {
        vis[node] = 1;
        recpath[node] = 1;
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(u == node){
                if(!vis[v]) {
                    if(dfs(v, vis, recpath, edges)) return true;
                }
                else if(recpath[v]) return true;
            }
        }
        recpath[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<int> recpath(n, 0);
        for(int i = 0;i < n;i++) {
            if(!vis[i]){
                if(dfs(i, vis, recpath, edges)) return false;
            }
        }
        return true;
    }
};
