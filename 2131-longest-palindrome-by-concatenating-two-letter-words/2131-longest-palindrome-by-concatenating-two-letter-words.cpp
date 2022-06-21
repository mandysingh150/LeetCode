class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        unordered_map<string,int> mp;
        for(auto i: a) {
            mp[i]++;
        }
        int cnt_same=0, cnt_diff=0;
        for(auto &[str, cnt]: mp) {
            string t=str;
            reverse(begin(t), end(t));
            if(str == t) {
                cnt_diff += (cnt/2) * 4;
                cnt_same = max(cnt_same, (cnt%2) * 2);
            }
            else if(mp.count(t)) {
                cnt_diff += min(cnt, mp[t]) * 4;
                cnt=0;
            }
        }
        return cnt_diff + cnt_same;
    }
};