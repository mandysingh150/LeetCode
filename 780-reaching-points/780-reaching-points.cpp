class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx or ty<sy) {
            return 0;
        }
        if(sx == tx) {
            return (ty-sy)%sx==0;
        }
        if(sy == ty) {
            return (tx-sx)%sy==0;
        }
        return tx>=ty ? reachingPoints(sx, sy, tx%ty, ty) : reachingPoints(sx, sy, tx, ty%tx);
    }
};