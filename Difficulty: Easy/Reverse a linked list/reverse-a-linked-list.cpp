/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        
        // store prev element currently point to null that is left to 1
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            // before cut the connection with 2 make it next
            Node* next = curr -> next; // local variable so not affect the global next and working fine 
            // Now curr point to previous element 
            curr -> next = prev;
            
            // Now shift the prev to curr
            prev = curr;
            // also move curr to next to continue step repeatedly
            curr = next;
        }
        // return prev as it point to the last node other[curr and next point to null]
        return prev; 
        
        
    }
};