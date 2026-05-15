class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        //Brute Force --> TC = O(N^2) SC = O(1)
        // for(int i = 1; i <= arr.size() + 1; i++ ) {
        //     bool found = false;
            
            
        //     for(int j = 0; j <  arr.size(); j++) {
        //         if(arr[j] == i ) {
        //              found = true;
        //              break;
                     
        //         }
                
                
        //     }
        //     if(found == false) {
        //           return i;
        //         }
                
        // }
        
        // return -1;
        
        // Better Approach [Hashing]  --> TC = O(N) SC = O(N)
        //store element in the hash array or unorderd_set 
        
        // using hashArray
        // int missingNum;
        // int n = arr.size() + 1; // n = 8 array size = 7
        // //initialize all with the 0 
        // vector<int> hashArray(n + 1, 0); // we have to store 8 no in the hashArray and it is 0 based indexing so n + 1 [0,1,2,3,4,5,6,7,8]
        
        // for(int i = 0; i < arr.size(); i++ ) {
        //     int noThatPush = arr[i];
        //     hashArray[noThatPush] = 1; // 0 become 1 if again repeat then it become 2  // But here we are marking present 
        // }
        // for(int i = 1; i < n + 1; i++ ) {
        //     if(hashArray[i] == 0 ) {
        //         missingNum = i;
        //     }
        // }
        
        // return missingNum;
        
        
        //using unordered_set
        // #include<unordered_set> // no need to metion because it is already present in #include<bits/stdc++.h> library 
        // unordered_set<int> mySet;
        
        // for(int i = 0; i < arr.size(); i++ ) {
        //     mySet.insert(arr[i]); // we insert all the no of the array inside the mySet
        // }
        
        // for(int i = 1; i <= arr.size() + 1; i++ ) { // now check in the mySet that number is present or not 
        //     if(mySet.count(i) == 0 ) {
        //         return i; 
        //     }
        // }
        
        // Optimal Approach -1
        
        // int missingNumber;
        // long long n = arr.size() + 1;
        // int sum = ((n * (n + 1 ))/2);
        
        // int arrSum = 0;
        // for(int i = 0; i < arr.size(); i++ ) {
            
        //     arrSum += arr[i];
        // }
        
        // missingNumber = sum - arrSum;
        // return missingNumber;
        
        
          // Optimal Approach -2 XOR approach --> pair cancillation 
          
          int n = arr.size() + 1;
          int xorNumber = 0;
          int xorArray = 0;
          int missingNumber;
          
          // xor all the no from 1 to n
          for(int i = 1; i <= n; i++ ) {
              xorNumber = xorNumber ^ i;
          }
          
          // xor all the array element
          for(int i = 0; i < arr.size(); i++ ) {
              xorArray = xorArray ^ arr[i];
          }
          
          // xor xorNumber and xorArray it cancil the duplicate one and return the remaining element that is missing element 
          missingNumber = xorNumber ^ xorArray;
          return missingNumber;
        
        
        
        
       
        
    }
};