class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        for(int si=0, ei=a.size()-1 ; si<ei ; ) {
            int mid = (si+ei)/2;
            if(a[si] + a[ei] == x) {
                return {si+1, ei+1};
            }
            else if(a[si]+a[ei] < x) {
                si++;
            }
            else {
                ei--;
            }
        }
        return {};
    }
};