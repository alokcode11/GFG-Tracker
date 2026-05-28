/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> preOrder; // store traversal 
        // Create ptr to Node move around binary tree
        Node* curr = root;
        
        // Move till curr not point to null
        while(curr != NULL) {
            
            // tackle in two way left exist or not
            // if left not exist
            if(curr -> left == NULL) {
               
               // process curr and go right 
               preOrder.push_back(curr -> data);
               curr = curr -> right;
            }
            else { // if left exist
                 // first find the rightmost node in the left subtree(inoder predecessor)
                 Node* IP = curr -> left;
                 
                 // move rightmost to the left of curr
                 while(IP -> right != NULL && IP -> right != curr) {
                     IP = IP -> right;
                 }
                 // Here two ways found :  first time visiting left subtree - create thread with curr
                 if(IP -> right == NULL) {
                     IP -> right = curr;
                     preOrder.push_back(curr -> data); // push the root value first
                     curr = curr -> left; // Go to again leftsubtree
                 }else {  // delete thread
                     // if not equal to Null and point to the curr
                     IP -> right = NULL; // remove thread 
                     curr = curr -> right; // root then move its right subtree
                     }
            }
        }
        return preOrder;
    }
};