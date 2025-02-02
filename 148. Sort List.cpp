/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> ss;
        ListNode* temp =head;
        while(temp){
            ss.push_back(temp->val);
            temp=temp->next;
        }
        sort(ss.begin(),ss.end());
        int i =0;
        temp = head;
        while(temp){
            temp->val=ss[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};
