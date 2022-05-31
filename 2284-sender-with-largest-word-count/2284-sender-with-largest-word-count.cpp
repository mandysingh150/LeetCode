class Solution {
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {
        unordered_map<string,int> mp;
        for(int i=0 ; i<m.size() ; ++i) {
            int cnt = 1;
            for(auto j: m[i]) {
                if(j == ' ')
                    cnt++;
            }
            mp[s[i]] += cnt;
        }
        vector<pair<int,string>> v;
        for(auto [a,b]: mp) {
            v.push_back({b,a});
        }
        sort(v.begin(), v.end());
        int mx = v.back().first;
        vector<string> ss;
        for(int i=v.size()-1 ; i>=0 and v[i].first==mx ; --i) {
            ss.push_back(v[i].second);
        }
        sort(ss.begin(), ss.end());
        
        for(auto i: ss) {
            cout<<i<<" ";
        }
        cout<<endl;
        // , [](pair<int,string> &c, pair<int,string> &d) {
        //     if(c.first == d.first) {
        //         if(c.second.size() == d.second.size())
        //             return c.second.compare(d.second) > 0;
        //         return c.second.size() < d.second.size();
        //     }                
        //     return c.first < d.first;
        // });
        // string ans;
        // for(int i=v.size()-2 ; i>=0 ; --i) {
        //     if(v[i].first != v[i+1].first)
        //         return v[i+1].second;
        // }
        // , [](pair<int,string> &c, pair<int,string> &d) {
        //     if(c.first == d.first)
        //         return c.second.compare(d.second) > 0;
        //     return c.first > d.first;
        // });
        return v.back().second;
    }
};