class Solution {
public:
    int count(vector<int>& nums, int i,vector<int>& memo){
        if(i>=nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int pick = nums[i]+count(nums,i+2,memo);
        int not_pick = count(nums,i+1,memo);
        return memo[i]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n,-1);
        return count(nums,0,memo);
    }
};
