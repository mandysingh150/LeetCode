class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        for(auto i: arr) {
            pq.push({abs(x-i), i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> v;
        while(pq.size()) {
            auto [a, b] = pq.top();
            pq.pop();
            v.push_back(b);
        }
        sort(begin(v), end(v));
        return v;
    }
};