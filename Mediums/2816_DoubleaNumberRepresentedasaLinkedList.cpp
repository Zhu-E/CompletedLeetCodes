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
    ListNode* doubleIt(ListNode* head) {
        int ans = recurse(head);
        if(ans == 0){
            return head;
        }
        return new ListNode(ans, head);
    }
    int recurse(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int curVal = 2*head->val+recurse(head->next);
        head->val = curVal%10;
        return curVal/10;
    }
};
