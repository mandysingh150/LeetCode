class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> t = a;
        sort(a.begin(), a.end());
        int si=0, ei=a.size()-1;
        while(si<=ei and a[si]==t[si]) si++;
        while(si<=ei and a[ei]==t[ei]) ei--;
        return ei-si+1;
    }
};