/*structure of the node of the DLL
class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        
        Node* newNode = new Node(x); 
        // Case 1 : No element / head = NULL just return newHead;
        if(head == nullptr) return newNode;
        
        // Case 2 : if 1 Node then we have to explicitly tackle this 
        if(x <= head -> data) {
            newNode -> next = head;
            head -> prev = newNode;
            return newNode;
        }
        
        // Case 3 : for the intermediate or list Node insertion
        // Now find the correct position to insert node
        Node* curr = head; // traverse the DLL
        while(curr -> next != nullptr && curr -> next -> data <= x) {
            curr = curr -> next;
        }
        // now made link but follow the correct link steps otherwise connection crash
        newNode -> next = curr -> next ; // also suitable for x is inserted at last node as curr -> next = null is acceptable here 
        newNode -> prev = curr; 
        // But for Null -> prev fault so first check that curr next is not null
        if(curr -> next != nullptr) {
            curr -> next -> prev = newNode;
        }
        curr -> next = newNode;
        
        return head; 
        
    }
};