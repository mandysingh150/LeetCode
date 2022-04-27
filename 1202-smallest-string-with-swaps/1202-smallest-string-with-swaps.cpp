class Solution {
public:
    int find(int source, vector<int> &par) {
        return (par[source] == source ? source : par[source]=find(par[source], par));
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> par(s.size());
        iota(begin(par), end(par), 0);
        for(auto i: pairs) {
            int x = find(i[0], par);
            int y = find(i[1], par);
            if(x != y) {
                par[y] = x;
            }
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0 ; i<s.size() ; ++i) {
            mp[find(par[i], par)].push_back(i);
        }
        for(auto [parent, child]: mp) {
            string t="";
            for(auto ele: child) {
                t += s[ele];
            }
            sort(begin(t), end(t));
            int in=0;
            for(auto ele: child) {
                s[ele] = t[in++];
            }
        }
        return s;
    }
};