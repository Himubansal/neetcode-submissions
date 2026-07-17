class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int, vector<pair<int,int>>> adj;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int manh_dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,manh_dist});
                adj[j].push_back({i,manh_dist});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<bool> vis(n,false);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto [w, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            vis[node]=true;
            sum+=w;

            for(auto& [neigh, dis]: adj[node]){
                if(!vis[neigh])
                    pq.push({dis,neigh});
            }
        }
        return sum;
    }
};
