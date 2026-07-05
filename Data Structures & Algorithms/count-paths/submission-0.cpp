class Solution {
public:
    int dfs(vector<vector<int>>& memo, int i,int j,int m,int n){
        if(i==m-1 && j==n-1) return 1;
        if(memo[i][j]!=-1) return memo[i][j];
        int ways=0;
        if(i+1 < m) ways+=dfs(memo,i+1,j,m,n);
        if(j+1 < n) ways+=dfs(memo,i,j+1,m,n);

        return memo[i][j]=ways;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return dfs(memo,0,0,m,n);
    }
};
