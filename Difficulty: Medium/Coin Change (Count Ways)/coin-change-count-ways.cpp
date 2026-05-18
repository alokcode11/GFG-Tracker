class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        
        // dp[target] stores the no of ways
        // create the dp of size sum + 1 and init with 0
        vector<int> dp(sum + 1, 0);
        
        // dp[0] has one way ie do nothing --> 1 way to make sum 0
        dp[0] = 1;
        
        
        // Traverse every coin
        for(int i = 0; i < coins.size(); i++ ) {
            
            // Update the all target
            for(int target = coins[i]; target <= sum; target++ ) {
                
                dp[target] = dp[target] + dp[target - coins[i]];
            }
        }
        // return the no of ways of the last value that is sum 
        // number of ways to make the required sum
        return dp[sum];
    }
};

// TC = O(n * sum)
// SC = O(sum + 1)