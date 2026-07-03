class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest =0;
        int n=nums.size();
        for(int x:nums){
            if(s.find(x-1)==s.end()){
                int curr = x;
                int len=1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;
    }
};
