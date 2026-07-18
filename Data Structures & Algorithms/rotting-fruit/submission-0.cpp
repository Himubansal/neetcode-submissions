class Solution {
public:
    vector<vector<int>> dr = {{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0,time=0;

        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        
        while(!q.empty() && fresh>0){
            int sz = q.size();

            while(sz--){
                auto [i,j] = q.front();
                q.pop();

                for(auto& d : dr){
                    int ni = i+d[0];
                    int nj = j+d[1];

                    if(ni<0 || nj<0 || ni>=m || nj>=n || grid[ni][nj]!=1) continue;

                    grid[ni][nj]=2;
                    fresh--;
                    q.push({ni,nj});
                }
            }
            time++;
        }
        return (fresh==0)?time:-1;
    }
};
