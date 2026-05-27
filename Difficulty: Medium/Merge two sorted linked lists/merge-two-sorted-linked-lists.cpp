/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* newNode = new Node(-1);
        Node* curr = newNode; 
        
        while(head1 != NULL && head2 != NULL) {
            // head1.data is smaller
            if(head1 -> data <= head2 -> data) {
               curr -> next = head1;
               head1 = head1 -> next;
            }
            // head2.data is smaller
            else {
               curr -> next = head2;
               head2 = head2 -> next;
            }
            curr = curr -> next; // Move curr forwared
        }
        // if any list is left then append it to newNode
        if(head1 != NULL)  curr -> next = head1;
        
        if(head2 != NULL)  curr -> next = head2;
        
        // Return the acutal merged head ie newNode next
        return newNode -> next; 
    }
};