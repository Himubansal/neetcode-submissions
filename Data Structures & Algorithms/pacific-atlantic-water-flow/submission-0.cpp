class Solution {
public:

    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& visited){
        int m=heights.size();
        int n=heights[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return;

        if(heights[i][j] < prev || visited[i][j]) return;
        visited[i][j] = 1;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for (int d = 0; d < 4; d++) {
            dfs(heights, i + dx[d], j + dy[d], heights[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            dfs(heights,i,0,-1,pacific);
            dfs(heights,i,n-1,-1,atlantic);
        }

        for(int j=0;j<n;j++){
            dfs(heights,0,j,-1,pacific);
            dfs(heights,m-1,j,-1,atlantic);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};
