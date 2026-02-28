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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr){
            return nullptr;
        }
        ListNode* cur = head;
        ListNode* skip = head;
        ListNode* prev = head;
        while(skip!=nullptr){
            skip=skip->next;
            if(skip==nullptr){
                prev->next=cur->next;
                return head;
            }
            else{
                skip=skip->next;
            }
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        return head;
    }
};
