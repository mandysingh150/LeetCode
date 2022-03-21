class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,pair<int,int>> mp;
        for(int i=0 ; i<s.size() ; ++i) {
            if(mp.count(s[i]))
                mp[s[i]].second = i;
            else
                mp[s[i]] = {i,i};
        }
        vector<int> v;
        for(int i=0 ; i<s.size() ; ++i) {
            int ei=mp[s[i]].second, len=0, j=i;
            for( ; j<=ei ; ++j) {
                len++;
                ei = max(mp[s[j]].second, ei);
            }
            i=j-1;
            v.push_back(len);
        }
        return v;
    }
};