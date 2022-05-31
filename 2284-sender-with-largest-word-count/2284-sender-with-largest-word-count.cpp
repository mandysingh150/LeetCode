class Solution {
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {
        string ans;
        int mx=0;
        unordered_map<string,int> mp;
        for(int i=0 ; i<s.size() ; ++i) {
            int cnt = count(begin(m[i]), end(m[i]), ' ') + 1;
            int total = mp[s[i]] += cnt;
            if(total > mx || (total==mx and s[i]>ans)) {
                mx = total;
                ans = s[i];
            }
        }
        return ans;
    }
};