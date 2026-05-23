class Solution {
  public:
  
    int expandAroundCenter(string &s, int left, int right) {
        int localCount = 0;
        int n = s.length(); 
        
        // check the boundary till which left and right move
        // also check the left and right are equal then move left-- and right++ and again check that it is palindrome or not 
        while(left >= 0 && right <= n - 1 && s[left] == s[right]) {
            
            // But we only have to consider the s whose length is >= 2 
            if(right - left + 1 >= 2) {
                localCount++;
            }
            // now check its left and right and again check it is palindrome or not 
            left--;
            right++; 
        }
        // return the localCount for every i 
        return localCount; 
        
    }
    int countPS(string &s) {
        // code here
        int count = 0;
        int n = s.size(); // length() is also applicable for the string 
        
        int oddCount = 0;
        int evenCount = 0; 
        // for every i calculate the even and odd count
        for(int i = 0; i <= n - 1; i++) {
            
            // count odd length palindrome
            oddCount += expandAroundCenter(s, i , i);
            
            // Even count length palindrome
            evenCount += expandAroundCenter(s, i, i + 1);
            
        }
        // total count
        count = oddCount + evenCount;
        
        return count;
        
        
        
    }
};