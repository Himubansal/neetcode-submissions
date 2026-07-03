class Solution {
public:
    string encode(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(auto& s : strs){
            ans += to_string(s.size()) + '#' + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.size();
        while (i < n) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));

            string str = s.substr(j + 1, len);
            ans.push_back(str);

            i = j + 1 + len;
        }
        return ans;
    }
};
