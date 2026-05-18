class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        
        // just swap the i and i + 1 element 
        // arr is already sorted 
        for(int i = 0; i < arr.size() - 1; i+= 2 ) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
      
        
    }
};