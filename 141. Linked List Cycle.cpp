/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map <ListNode*,int> mp;
        if(!head || !head->next){
            return false;
        }
        while(head->next){
            mp[head->next]++;
            if(mp[head->next]>1){
                return true;
            }
            head=head->next;
        }
        return false;
    }
};
