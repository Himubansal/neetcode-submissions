class Solution {
public:
    unordered_set<string> dict;
    bool canBreak(string& s, int i,vector<int>& memo){
        if(i==s.size()) return true;
        if(memo[i]!=-1) return memo[i];
        for(int j=i+1;j<=s.size();j++){
            string sub = s.substr(i,j-i);
            if(dict.count(sub) && canBreak(s,j,memo)) return memo[i]=true;
        }
        return memo[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(),-1);
        return canBreak(s,0,memo);
    }
};
