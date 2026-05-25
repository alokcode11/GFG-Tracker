class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        // create a mask with 1 at kth posn 
        // n & mask !== 0 means bit set to 1 otherwise false 
        int mask = (1 << k); // left shift
        
        // Do bitwise and with n 
        if((n & mask) != 0) {
            return true;
        }
        return false; 
    }
};