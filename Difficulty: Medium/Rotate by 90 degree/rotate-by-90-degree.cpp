class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        
        int n = mat.size();
        // Step 1 : Transpose the matrix
        for(int i = 0; i <= n - 1; i++) {
            for(int j = i + 1; j <= n - 1; j++) {
                // interchange i and j to transpose the mat
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Step 2 : Reverse the col as this in acw 
        for(int col = 0; col < n; col++) {
            
            // col is fix so nothing to do 
            // we have to swap top and bottom of the i 
            int top = 0;
            int bottom = n - 1;
            
            // n/2 part reverse all reversed
            while(top < bottom) {
                // swap i top and bottom
                swap(mat[top][col], mat[bottom][col]);
                
                top++;
                bottom--;
            }
        }
    }
};
