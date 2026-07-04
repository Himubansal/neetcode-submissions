class DisjointSet{
public:
    vector<int> ULParent,RankBySize;

    DisjointSet(int n){
        ULParent.resize(n+1);
        RankBySize.resize(n+1);
        for(int i=0;i<=n;i++){
            ULParent[i]=i;
            RankBySize[i]=1;
        }
    }

    int findParent(int u){
        if(u==ULParent[u]){
            return u;
        }
        return ULParent[u]=findParent(ULParent[u]);
    }

    void UnionByRank(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;
        if(RankBySize[ulp_u] < RankBySize[ulp_v]){
            ULParent[ulp_u] = ulp_v;
            RankBySize[ulp_v]+=RankBySize[ulp_u];
        }
        else{
            ULParent[ulp_v] = ulp_u;
            RankBySize[ulp_u]+=RankBySize[ulp_v];
        }
    } 
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int cnt=0;

        for(int i=0;i<edges.size();i++)
            ds.UnionByRank(edges[i][0],edges[i][1]);

        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++){
            int init = ds.findParent(i);
            freq[init]++;
        }
        for(int x:freq){
            if(x>0) cnt++;
        }
        
        return cnt;
    }
};
