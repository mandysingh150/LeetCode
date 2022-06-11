class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<pair<int,int>>> row(m, vector<pair<int,int>>{{-1,-1}, {n, -1}}), col(n, vector<pair<int,int>>{{-1,-1}, {m,-1}});
        for(auto i: g) {
            row[i[0]].push_back({i[1], 0});
            col[i[1]].push_back({i[0], 0});
        }
        for(auto i: w) {
            row[i[0]].push_back({i[1], -1});
            col[i[1]].push_back({i[0], -1});
        }
        for(int i=0 ; i<m ; ++i) {
            sort(row[i].begin(), row[i].end());
        }
        for(int i=0 ; i<n ; ++i) {
            sort(col[i].begin(), col[i].end());
        }
        int cnt=0;
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                auto r = lower_bound(row[i].begin(), row[i].end(), pair<int,int>{j, -1});
                auto c = lower_bound(col[j].begin(), col[j].end(), pair<int,int>{i, -1});
                
                if(r->first!=j and c->first!=i and r->second==-1 and c->second==-1 and prev(r)->second==-1 and prev(c)->second==-1)
                    cnt++;
            }
        }
        return cnt;
    }
};