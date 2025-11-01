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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> to_remove;
        for(auto i : nums){
            to_remove.insert(i);
        }
        auto prev = head;
        for(auto i = head; i != NULL; i=i->next){
            if(to_remove.count(i->val)==1){
                if(prev==i){
                    head=head->next;
                    prev=head;
                }
                else{
                    prev->next = i->next;
                }
            }
            else{
                prev = i;
            }
        }
        return head;
    }
};
