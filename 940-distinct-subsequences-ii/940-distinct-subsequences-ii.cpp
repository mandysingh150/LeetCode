#define mod int(1e9+7)
class Solution {
public:
    int distinctSubseqII(string &s) {
        long long ends_with[26]={0};
        for(auto ch: s) ends_with[ch-'a'] = accumulate(begin(ends_with), end(ends_with), 1ll) % mod;
        return accumulate(begin(ends_with), end(ends_with), 0ll) % mod;
    }
};