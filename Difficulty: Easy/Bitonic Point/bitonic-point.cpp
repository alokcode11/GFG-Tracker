// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        
        // Brute Force  --> TC = O(N)  SC = O(1)
        // int bitonicPoint = INT_MIN;  // this is the max in the array
        // for(int i = 0; i < arr.size(); i++ ) {
        //     if(arr[i] > bitonicPoint ) {
        //         bitonicPoint = arr[i];
        //     }
        // }
        // return bitonicPoint;
        
        //optimal Approach --> TC = O(log(n))  SC = O(1)
        
        int low = 0;
        int high = arr.size() - 1;
        int peak;
        // “Continue while multiple elements still exist”
        while(low < high ) {  // not equal to beacuse Continue binary search until only one element remains
        int mid = low + (high - low ) / 2;
            
            if(arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            else { // if mid is greater then it may be Bitonic point that why it is inclusive 
                high = mid; 
            }
            // when low == high triggers exit out of the loop 
        }
        peak = arr[low]; // we can also use high here because both are equal 
       
        return peak;
        
    }
};