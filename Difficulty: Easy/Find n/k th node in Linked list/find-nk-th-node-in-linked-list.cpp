/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    int fractionalNode(struct Node *head, int k) {
        // your code here
        
        // Step 1 : find the length of the ll
        Node* temp = head;
        int length = 0;
        
        while(temp != NULL) { // for safety l = 0 and temp.next != null bcz if next not exist then crash
            // temp is head so update the length 
            length++;
            // now update the temp to next 
            temp = temp -> next;
        }
        
        // Step 2 : find required position
        
        // int position = (length + k - 1) / k;
        int position;
        if(length % k == 0) {
            position = length / k; 
        }
        else {
            position = ((length / k ) + 1);
        }
        
        //Step 3 : Traverse to required node and give the data of node 
        
        // now again want temp that point to head currently it is point to the null that used in counting of the no of the nodes in the linklist
        temp = head;
        int count = 1;
        
        while(count < position) { // here temp != null is irrelavant 
            temp = temp -> next;
            count++;
        }
        
        // after sucessfully traversal of temp it moved to the required position whose data we want so return that 
        return temp -> data; 
    }
};