class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int, greater<int>> s;
        vector<vector<int>> ans, v;
        for(auto i: buildings) {
            v.push_back({i[0], i[2]});
            v.push_back({i[1], -i[2]});
        }
        sort(begin(v), end(v));
        int prev=0;
        for(int i=0 ; i<v.size() ; ) {
            int x=v[i][0];
            while(i<v.size() and v[i][0] == x) {
                if(v[i][1] > 0) {
                    s.insert(v[i][1]);
                }
                else {
                    s.erase(s.find(-v[i][1]));
                }
                i++;
            }
            int top = *begin(s);
            if(prev != top) {
                ans.push_back({x, top});
                prev = top;
            }
        }
        return ans;
    }
};