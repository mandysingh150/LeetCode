class Solution {
public:
    vector<int> ans;
    void help(vector<pair<int,int>> &a, int si, int ei) {
        if(si >= ei) return;
        int mid = (si+ei)/2;
        help(a, si, mid);
        help(a, mid+1, ei);
        
        // merge in descending order and update the answer array
        vector<pair<int,int>> t(ei-si+1);
        int i=si, j=mid+1, k=0;
        while(i<=mid and j<=ei) {
            if(a[i].first <= a[j].first) {
                t[k++] = a[j++];
            }
            else {
                ans[a[i].second] += ei-j+1;
                t[k++] = a[i++];
            }
        }
        while(i<=mid) t[k++] = a[i++];
        while(j<=ei) t[k++] = a[j++];
        for(int i=si ; i<=ei ; ++i) {
            a[i] = t[i-si];
        }
    }
    vector<int> countSmaller(vector<int>& a) {
        ans = vector<int>(a.size(), 0);
        vector<pair<int,int>> v(a.size());
        for(int i=0 ; i<a.size() ; ++i) {
            v[i] = {a[i], i};
        }
        help(v, 0, a.size()-1);
        return ans;
    }
};