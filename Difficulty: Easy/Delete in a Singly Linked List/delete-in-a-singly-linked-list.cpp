/*
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        
        // Edge case : if no element is there then return null 
        if(head == NULL) return NULL;
        
        // if only one element then heat.next become null so it also return null
        // This condition is take care of that 
        
        // if we have to del the head 
        if(x == 1) {
            // store head in temp 
            Node* temp = head;
            head = head -> next; // shift head to next node 
            delete temp;
            
            return head; 
        }
        
        // if we have to delete the middle or last element 
        
        Node* curr = head;
        Node* prev = NULL;
        int count= 1; // 1 based idx
        
        while(count < x) {
            prev = curr;
            curr = curr -> next; // iterator to reach till x
            count++;
        }
        // remove the connection of the curr node 
            prev -> next = curr -> next;
            
            delete curr;
            
            return head; 
    }
};