class Solution {
  public:
    // Function to display the elements of a linked list in same line
    void printList(Node *head) {
        while(head){
            cout<<head->data<<" ";
            head=head->next;
        }
        // your code goes here
    }
};
