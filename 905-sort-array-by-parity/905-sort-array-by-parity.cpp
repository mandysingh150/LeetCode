class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> a;
        for(auto i: nums) if(!(i&1)) a.push_back(i);
        for(auto i: nums) if(i&1) a.push_back(i);
        return a;
    }
};