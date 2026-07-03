class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int ans=0;
        int i=0,maxFreq=0;
        for(int j=0;j<s.size();j++){
            freq[s[j]-'A']++;
            int len = j-i+1;
            maxFreq = max(maxFreq,freq[s[j]-'A']);
            if(len-maxFreq > k){
                freq[s[i]-'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
