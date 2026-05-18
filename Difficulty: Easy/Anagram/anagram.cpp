class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        // using frequency array 
        
        // Length must be same 
        if(s1.length() != s2.length()) return false; 
        
       unordered_map<char, int> frequency;
       
       // add this to the hashmap 
       for(int i = 0; i < s1.size(); i++) {
           frequency[s1[i]]++;
       }
       
       // remove this from the hashmap
       for(int i = 0; i < s2.size(); i++) {
           frequency[s2[i]]--;
       }
       
       // Now check that hashmap has any value or not 
       //check all frequency become 0 or not 
       for(auto it: frequency) {
           
           if(it.second != 0) return false;
       }
       return true; 
    }
};
     // Time Complexity: O(n + m)
    // Auxiliary Space: O(1)