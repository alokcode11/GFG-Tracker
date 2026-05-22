class Solution {
  public:
     
    // function that find the maxSum in an array  // Kadane's Algorithm
    int kadane(vector<int>& arr) {
        int sum = 0;
        int maxi = INT_MIN;

        for(int i = 0; i <= arr.size() - 1; i++) {
            
            // do the current sum of arr
            sum += arr[i];
            maxi = max(maxi, sum);
            
            // if sum < 0  Discard the negative sum 
            if(sum < 0) sum = 0;
        }
        return maxi;
        
    }
    
       
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        
        // find the rows and cols
        int rows = mat.size();
        int cols = mat[0].size();
        
        // init the maxRectangleSum -> store the final maxSum of rectangle 
        int maxRectangleSum = INT_MIN;
        
        // fixed the top row 
        for(int topRow = 0; topRow <= rows - 1; topRow++) {
            
            // Compressed array that store row its size equal to the no of cols 
            // init all the rows value with the 0 
            vector<int> temp(cols, 0); 
            
            // now move bottomRow from the topRow to rows 
            for(int bottomRow = topRow; bottomRow <= rows - 1; bottomRow++) {
                
                // add the currRow into the temp whose size = cols
                for(int col = 0; col <= cols - 1; col++) {
                    
                    // [0, 0, 0] -> [-2, 6, 4] -> [-2+ 1, 6 + 3, 4 - 5]
                    temp[col] += mat[bottomRow][col]; 
                }
                // find the maxSum of the current subArray sum 
                int currMaxArrSum = kadane(temp);
                
                // update the maxRectangleSum
                maxRectangleSum = max(maxRectangleSum, currMaxArrSum);
            }
        }
        return maxRectangleSum;
    }
};

// Fix rows
// Compress columns
// Kadane on columns
// Tc - O(row* row * col ) = O(n^ 2 * m)
// Sc - O(n)
