class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);

        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findParent(int u){
        if(u==parent[u]){
           return u;
        }
        return parent[u]=findParent(parent[u]);
    }

    bool unite(int u, int v){
        int u_par = findParent(u);
        int v_par = findParent(v);

        if(u_par==v_par) return false;

        if(rank[u_par]<rank[v_par]){
            parent[u_par] = v_par;
            rank[v_par]+=rank[u_par];
        }
        else{
            parent[v_par] = u_par;
            rank[u_par]+=rank[v_par];
        }

        return true;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        DSU ds(n);

        for(auto& e : edges){
            if(!ds.unite(e[0],e[1])) return {e[0],e[1]};
            ds.unite(e[0],e[1]);
        }
        return {};
    }
};
