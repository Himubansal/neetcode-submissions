class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProd = nums[0], curMax = nums[0], curMin = nums[0];
        
        for(int i=1;i<n;i++){
          int num=nums[i];
          if(num<0) swap(curMax,curMin);
          curMax = max(num, curMax * num); 
          curMin = min(num, curMin * num);
          maxProd = max(maxProd, curMax);
        }
        return maxProd;
    }
};
