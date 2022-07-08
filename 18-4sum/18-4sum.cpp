class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int x) {
        set<vector<int>> v;
        sort(begin(a), end(a));
        for(int i=0 ; i<a.size() ; ++i) {
            for(int j=i+1 ; j<a.size() ; ++j) {
                int k=j+1, l=a.size()-1;
                while(k<l) {
                    long long sum = 0ll+a[i]+a[j]+a[k]+a[l];
                    if(sum == x) {
                        v.insert({a[i], a[j], a[k], a[l]});
                        k++;
                        while(k<l and a[k-1]==a[k]) 
                            ++k;
                        l--;
                        while(k<l and a[l]==a[l+1]) 
                            --l;
                    }
                    else if(sum < x) {
                        k++;
                        while(k<a.size() and a[k-1]==a[k]) 
                            ++k;
                    }                        
                    else {
                        --l;
                        while(k<l and a[l]==a[l+1]) 
                            --l;
                    }
                }
            }
        }
        return vector<vector<int>>(begin(v), end(v));
    }
};