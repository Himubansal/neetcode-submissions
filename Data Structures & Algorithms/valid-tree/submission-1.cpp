class Solution {
public:
    bool dfs(int node,int parent,vector<bool>& visited,vector<vector<int>>& adj){
        visited[node]=true;
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                if(dfs(neigh,node,visited,adj)) return true;
            }
            else if(neigh!=parent) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            int to=edges[i][0];
            int from=edges[i][1];
            adj[to].push_back(from);
            adj[from].push_back(to);
        }

        if (dfs(0, -1, visited, adj)) return false;

        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
