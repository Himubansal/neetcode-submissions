class Solution {
public:
    int count(vector<int>& nums, int left,int right){
        int prev=0;
        int prev2=0;
        for(int i=left;i<=right;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int not_take = prev;
            int curr = max(take,not_take);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(count(nums,0,n-2),count(nums,1,n-1));
    }
};
