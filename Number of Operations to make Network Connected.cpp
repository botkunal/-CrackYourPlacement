class Solution {
    void dfs(vector<int> adj[],vector<bool> &visited,int src){
        visited[src]=true;
        for(int i:adj[src]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len=connections.size();
        if(len<n-1) return -1;
        vector<int> adj[n];
        for(auto a:connections){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                ans++;
            }
        }
        return ans-1;
    }
};
