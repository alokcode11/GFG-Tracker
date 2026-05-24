class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        
        // Base Case : if there is only one disc left in the starting
        if(n == 1) return 1; 
        
        // No of moves 
        long long moves = 0; 
        
        // Move n - 1 disc from "from " to "aux" using "to" helper function
        moves += towerOfHanoi(n - 1, from, aux, to);
        
        // Move the actual nth disc from "from" to "to"
        moves += 1;
        
        // Now move the n - 1 disks from "aux" to "to" using "from" helper function
        moves += towerOfHanoi(n - 1, aux, to, from);
        
        return moves; 
            
    }
};