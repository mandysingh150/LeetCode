class Solution {
public:
    unordered_map<string,bool> mp;
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx>tx or sy>ty)
            return 0;
        if(sx==tx)
            return (ty-sy)%sx==0;
        if(sy==ty)
            return (tx-sx)%sy==0;
        
        if(tx > ty)
            return reachingPoints(sx, sy, tx%ty, ty);
        else if(tx < ty)
            return reachingPoints(sx, sy, tx, ty%tx);
        return 0;
    }
};