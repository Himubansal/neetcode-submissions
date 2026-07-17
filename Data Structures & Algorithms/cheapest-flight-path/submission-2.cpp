class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        queue<tuple<int,int,int>> q;
        vector<int> dist(n,INT_MAX);
        q.push({src,0,0});
        dist[src]=0;

        int ans=INT_MAX;

        while(!q.empty()){
            auto [node, cost, stops] = q.front();
            q.pop();

            if(stops > k) continue;

           for(auto& [neigh,price]: adj[node]){
                int currDist = cost + price;

                if(neigh==dst) ans=min(ans,currDist);

                if(stops<k && currDist < dist[neigh]){
                    dist[neigh]=currDist;
                    q.push({neigh,currDist, stops+1});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
