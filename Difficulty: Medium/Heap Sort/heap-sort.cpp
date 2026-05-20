// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
        
    //Rearranges the array to maintain the max-heap property 
    void heapify(vector<int>& arr, int n,int i) {
        int largest = i;
        int left = (2 * i + 1);
        int right = (2 * i + 2);
        
        // if left child is greater than the root
        if(left <= n - 1 && arr[left] > arr[largest])  largest = left;
        
        // if right child is greater then the largest so far
        if(right <= n - 1 && arr[right] > arr[largest]) largest = right;
        
        // if largest is not root then we have to swap to maintain the max heap property 
        if(largest != i) {
            swap(arr[i], arr[largest]);
            
            // Recursively heapify the remaining sub tree till the largest reached to leaf
            heapify(arr, n, largest);
        }
    }
  
  
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        
        //Build a maxHeap [Bottom up approach]
        // start from the last non leaf node to root
        int n = arr.size();
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        
        // extract or del element one by one from the root
        // i = 0 exclude because it is already sorted you may or may not considered 
        for(int i = n -1; i > 0; i--) {
            
            // Move the current root (max element) to the end of the unsorted portion
            swap(arr[i], arr[0]);
            // call max heapify on the reduced heap (size i)
            // max ele is always on the 0 index 
            // This pushes the new (smaller) root down to its correct place
            heapify(arr, i, 0);
        }
    }
};