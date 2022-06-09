class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        int si=0, ei=a.size()-1;
        while(si<ei) {
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
        return {-1,-1};
    }
};