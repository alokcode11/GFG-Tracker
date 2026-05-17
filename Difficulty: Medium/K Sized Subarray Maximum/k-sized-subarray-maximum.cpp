class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        //Brute Force
        // vector<int> ans;
        
        // for(int i = 0; i <= arr.size() - k; i++ ) {
        //     int maxi = INT_MIN;
            
        //     // Traverse the current window 
        //     for(int j = i; j < i + k; j++ ) {
        //         if(arr[j] > maxi ) {
        //             maxi = arr[j];
        //         }
        //     }
        //   ans.push_back(maxi);  
        // }
        // return ans;
        
        
        // Optimal Approach
        deque<int> dq; // Store index
        vector<int> ans;
        
        for(int i = 0; i <= arr.size() - 1; i++ ) {
            
            // Remove indexes that is outside the current window
            if(!dq.empty() && dq.front() <= i - k ) {   // i = 5 [5,4,3] valid  5-3 = 2 that why < and = are not valid
                dq.pop_front();
            }
            
            //Remove smaller element form the back because current element is bigger
            while(!dq.empty() && arr[dq.back()] <= arr[i] ) {
                dq.pop_back();
            }
            
            // Now Insert the current element
            dq.push_back(i);
            
            // If window size become K 
            // Front of deque = maximum element
            if(i >= k - 1) {  // 0,1,2 -> k - 1
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
        
    }
};