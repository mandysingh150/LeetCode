class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto comp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.first<b.first;
        };
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        for(auto [key, val]: mp) 
            pq.push({val, key});
        
        vector<int> v;
        while(k--) {
            auto [val, key] = pq.top();
            pq.pop();
            v.push_back(key);
        }
        return v;
    }
};