class Solution {
public:
    int nextGreaterElement(int n) {
        string t = to_string(n);
        next_permutation(begin(t), end(t));
        long long ans = stoll(t);
        return ans>INT_MAX or ans<=n ? -1 : ans;
    }
};