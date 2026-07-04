class Solution {
public:
    bool isPalindrome(string& s,int left,int right){
        while(left<right && s[left]==s[right]){
            left++;right--;
        }
        if(s[left]!=s[right]) return false;
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
