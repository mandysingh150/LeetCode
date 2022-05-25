class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int total=matrix[0].size()*matrix.size();
        int r1=0;
        int r2=matrix.size()-1;
        int c1=0;
        int c2=matrix[0].size()-1;
        
        while(c1<=c2 and r1<=r2){
            for(int i=c1;i<=c2 and ans.size()<total;i++){
                ans.push_back(matrix[r1][i]);
            }
            r1++;
            for(int i=r1;i<=r2 and ans.size()<total;i++){
                ans.push_back(matrix[i][c2]);
            }
            c2--;
            for(int i=c2;i>=c1 and ans.size()<total ;i--){
                ans.push_back(matrix[r2][i]);
                
            }
            r2--;
            for(int i=r2;i>=r1 and ans.size()<total;i--){
                ans.push_back(matrix[i][c1]);
            }
            c1++;
        }
        return ans;
    }
};