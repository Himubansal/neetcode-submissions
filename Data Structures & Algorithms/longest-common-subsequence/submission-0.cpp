class Solution {
public:
    int dfs(string& text1, string& text2,int i,int j,vector<vector<int>>& memo){
        if(i<0 || j<0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=0;
        if(text1[i]==text2[j]){
            ans=max(ans,1+dfs(text1,text2,i-1,j-1,memo));
        }
        else{
            ans=max({ans,dfs(text1,text2,i-1,j,memo),dfs(text1,text2,i,j-1,memo)});
        }
        return memo[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return dfs(text1,text2,m-1,n-1,memo);
    }
};
