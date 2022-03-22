class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int inc=1, dec=1;
        for(int i=1 ; i<a.size() ; ++i) {
            if(a[i]<a[i-1])
                dec=inc+1;
            else if(a[i]>a[i-1])
                inc=dec+1;
        }
        return max(inc, dec);
    }
};