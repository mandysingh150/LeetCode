class Solution {
public:
    int reverse(int x) {
        if(x==INT_MAX or x==INT_MIN) 
            return 0;
        bool is_neg=0;
        if(x<0) {
            is_neg=1;
            x*=-1;
        }
        long long s=0;
        while(x>0) {
            s = 10*s + x%10;
            x/=10;
        }
        if(is_neg) 
            s*=-1;
        if(s>INT_MAX or s<INT_MIN) 
            return 0;
        return s;
    }
};