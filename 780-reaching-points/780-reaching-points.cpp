class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // nice visualization by "nits2010" - https://leetcode.com/problems/reaching-points/discuss/375429/Detailed-explanation.-or-full-through-process-or-Java-100-beat
        // there is a trivial path in recursion tree when we move from (tx, ty) to (sx, sy)
        while(sx<tx and sy<ty)
            if(tx<ty) 
                ty%=tx;
            else 
                tx%=ty;
        return (sx==tx and sy<=ty and (ty-sy)%sx==0) or (sy==ty and sx<=tx and (tx-sx)%sy==0);
    }
};