class Solution {
public:
    int dfs(vector<int>& nums, int i,vector<int>& memo){
        int ans=1;
        if(memo[i]!=-1) return memo[i];
        for(int j=i+1;j<nums.size();j++){
            if(nums[j] > nums[i]){
                ans = max(ans,1+dfs(nums,j,memo));
            }
        }
        return memo[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int longest=0;
        vector<int> memo(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            longest=max(longest,dfs(nums,i,memo));
        }
        return longest;
    }
};
