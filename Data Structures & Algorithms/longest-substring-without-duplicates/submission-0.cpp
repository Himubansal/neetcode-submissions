class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,ans=0;
        //{char,index}
        unordered_map<char,int> seen(s.size());
        for(int j=0;j<s.size();j++){
            if(seen.find(s[j])!=seen.end() && i<s.size()){
                i = max(i,seen[s[j]]+1);
            }
            seen[s[j]]=j;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
