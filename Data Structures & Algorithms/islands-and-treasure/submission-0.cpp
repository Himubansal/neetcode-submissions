class Solution {
public:
const int INF = 2147483647;
vector<vector<int>> dr = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for (auto& d : dr) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                if (grid[ni][nj] != INF) continue;

                grid[ni][nj] = grid[i][j] + 1;
                q.push({ni, nj});
            }
        }

    }
};
