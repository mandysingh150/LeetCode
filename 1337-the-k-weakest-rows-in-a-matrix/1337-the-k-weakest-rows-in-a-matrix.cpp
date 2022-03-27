class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0 ; i<mat.size() ; ++i) {
            int cnt=0;
            for(auto j: mat[i])
                cnt+=j;
            pq.push({cnt, i});
        }
        vector<int> v;
        while(k--) {
            auto [cnt_1, i] = pq.top();
            pq.pop();
            
            v.push_back(i);
        }
        return v;
    }
};