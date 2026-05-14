class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        
        vector<int> ans;  
        // code here
        int minElement= arr[0];
        int maxElement = arr[0];
        
        for(int i = 1; i < arr.size(); i++ ) {
            if(arr[i] < minElement ) {
                minElement = arr[i];
            }
            if(arr[i] > maxElement ) {
                maxElement = arr[i];
            }
        }
        
        ans.push_back(minElement);
        ans.push_back(maxElement);
        
        return ans;
        
    }
};