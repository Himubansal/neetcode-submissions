class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    void dfs(vector<int>& nums, int target, int start){
        if(target==0){
            res.push_back(ans);
            return;
        }
        if(target<0) return;
        for(int i=start;i<nums.size();i++){
            ans.push_back(nums[i]);
            dfs(nums,target-nums[i],i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        dfs(nums,target,0);
        return res;
    }
};
