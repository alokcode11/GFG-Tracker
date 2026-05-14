class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {

        // Vector to store final answer
        vector<int> ans;

        // Edge case:
        // If array contains only one element
        if(arr.size() == 1) {
            ans.push_back(arr[0]);
            ans.push_back(arr[0]);

            return ans;
        }

        // Variables to store minimum and maximum
        int minimum;
        int maximum;

        // Initialize min and max using first two elements
        if(arr[0] < arr[1]) {
            minimum = arr[0];
            maximum = arr[1];
        }
        else {
            minimum = arr[1];
            maximum = arr[0];
        }

        // Variables used for pair comparison
        int smallerElement;
        int largerElement;

        // Process elements in pairs
        for(int i = 2; i + 1 < arr.size(); i += 2) {

            // Find smaller and larger element within pair
            if(arr[i] < arr[i + 1]) {

                smallerElement = arr[i];
                largerElement = arr[i + 1];
            }
            else {

                smallerElement = arr[i + 1];
                largerElement = arr[i];
            }

            // Update minimum
            if(smallerElement < minimum) {
                minimum = smallerElement;
            }

            // Update maximum
            if(largerElement > maximum) {
                maximum = largerElement;
            }
        }

        // Handle odd-sized array
        // Last element remains unprocessed
        if(arr.size() % 2 != 0) {

            int lastElement = arr[arr.size() - 1];

            if(lastElement < minimum) {
                minimum = lastElement;
            }

            if(lastElement > maximum) {
                maximum = lastElement;
            }
        }

        // Store final answer
        ans.push_back(minimum);
        ans.push_back(maximum);

        return ans;
    }
};