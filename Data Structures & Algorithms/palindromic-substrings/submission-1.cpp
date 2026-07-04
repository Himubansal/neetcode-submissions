class Solution {
public:
    void expand(string& s,int left,int right, int& cnt){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
            cnt++;
        }
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            expand(s,i,i,cnt);
            expand(s,i,i+1,cnt);
        }
        return cnt;
    }
};
