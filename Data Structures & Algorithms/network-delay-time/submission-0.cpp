class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto& edge: times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dist(n+1,INT_MAX);

        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto& [neigh, w] : adj[node]){
                if(dist[node] + w < dist[neigh]){
                    dist[neigh]=dist[node] + w;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        int ans=0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
