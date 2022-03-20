class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> top(6, 0), bot(6, 0), common(6, 0);
        for(int i=0 ; i<tops.size() ; ++i)
            if(tops[i] == bottoms[i])
                common[tops[i]-1]++;
            else
                top[tops[i]-1]++, bot[bottoms[i]-1]++;
        int val = INT_MAX;
        for(int i=0 ; i<6 ; ++i)
            if(common[i]+top[i]+bot[i] >= tops.size())
                val = min(val, min(top[i], bot[i]));
        return val==INT_MAX ? -1 : val;
    }
};