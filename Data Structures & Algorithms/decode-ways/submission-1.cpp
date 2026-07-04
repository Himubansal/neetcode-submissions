class Solution {
public:
    bool isValid(string& s){
        if(s[0]=='0') return false;
        if(stoi(s)>=1 && stoi(s)<=26) return true;
        return false;
    }
    int canBreak(string& s,int i,vector<int>& memo){
        if(i==s.size()) return 1;
        if(memo[i]!=-1) return memo[i];
        int ways =0;
        for(int j=1;j<=2 && j+i<=s.size();j++){
            string sub = s.substr(i,j);
            if(isValid(sub)){
                ways+=canBreak(s,i+j,memo);
            }
        }
        return memo[i]=ways;
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(),-1);
        return canBreak(s,0,memo);
    }
};
