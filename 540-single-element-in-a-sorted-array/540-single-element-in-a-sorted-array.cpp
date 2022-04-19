class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int exor=0;
        for(auto i: nums) exor^=i;
        return exor;
    }
};