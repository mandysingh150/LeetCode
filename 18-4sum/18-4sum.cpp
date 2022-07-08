class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int x) {
        vector<vector<int>> v;
        sort(begin(a), end(a));
        for(int i=0 ; i<a.size() ; ) {
            for(int j=i+1 ; j<a.size() ; ) {
                int k=j+1, l=a.size()-1;
                while(k<l) {
                    long long sum = 0ll+a[i]+a[j]+a[k]+a[l];
                    if(sum == x) {
                        v.push_back({a[i], a[j], a[k], a[l]});
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
                ++j;
                while(j<a.size() and a[j-1]==a[j])
                    ++j;
            }
            ++i;
            while(i<a.size() and a[i-1]==a[i])
                ++i;
        }
        return v;
    }
};