#define tup tuple<int,int,int>
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        vector<int> v(p.size());
        
        // {bloom_start_to_end_OR_person_arrival_time, flower_OR_person, update_OR_person_index}
        vector<tup> a;
        for(auto i: f) {
            a.push_back(tup{i[0], 0, 1});
            a.push_back(tup{i[1]+1, 0, -1});
        }
        for(int i=0 ; i<p.size() ; ++i) {
            a.push_back(tup{p[i], 1, i});
        }
        sort(a.begin(), a.end());
        int cnt=0;
        for(auto [a, b, c]: a) {
            if(b == 0) {
                cnt += c;
            }
            else {
                v[c] = cnt;
            }
        }
        return v;
    }
};