class Solution {
public:
    int rob(vector<int>& a) {
        if(a.size() <= 2) {
            return *max_element(begin(a), end(a));
        }
        for(int i=1 ; i<a.size() ; ++i) {
            a[i] = max(a[i-1], a[i]+(i-2>=0 ? a[i-2] : 0));
        }
        return a.back();
    }
};