class Solution {
public:
    int largestCombination(vector<int>& a) {
        vector<int> v(32, 0);
        for(auto i: a) {
            for(int j=0 ; j<32 ; ++j) {
                if((1<<j)&i)
                    v[j]++;
            }
        }
        return *max_element(begin(v), end(v));
    }
};