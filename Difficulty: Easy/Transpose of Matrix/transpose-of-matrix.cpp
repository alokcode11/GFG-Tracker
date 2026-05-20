class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        
        // inplace swaping is only possible for the n * n 
        int n = mat.size();
        
        for(int i = 0; i <= n - 1; i++) {
            
            // we have to only swap the upper traingular part 
            // otherwise double swapping done and no transpose 
            for(int j = i + 1; j <= n - 1; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }
};