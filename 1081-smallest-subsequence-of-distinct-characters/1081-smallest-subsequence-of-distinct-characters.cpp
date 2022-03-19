class Solution {
public:
    string smallestSubsequence(string s) {
        // to store last occurence of every character
        unordered_map<int,int> mp;
        for(int i=0 ; i<s.size() ; ++i) mp[s[i]]=i;
        string ans;
        vector<bool> seen(26, 0);
        for(int i=0 ; i<s.size() ; ++i) {
            if(seen[s[i]-'a'])
                continue;
            while(!ans.empty() and ans.back()>s[i] and mp[ans.back()]>i) {
                seen[ans.back()-'a']=0;
                ans.pop_back();
            }                
            ans.push_back(s[i]);
            seen[s[i]-'a']=1;
        }
        return ans;
    }
};