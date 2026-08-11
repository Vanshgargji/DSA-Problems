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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *before = dummy;
        ListNode *after = head;

        ListNode *curr = NULL;
        ListNode *prev = NULL;
        ListNode *nextNode = NULL;

        while(true){
            ListNode *cursor = after;

            for(int i=0; i<k; i++){
                if(!cursor) return dummy->next;
                cursor = cursor->next;
            }

            curr = after;
            prev = before;

            for(int i=0; i<k; i++){
                nextNode = curr->next;

                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            after->next = curr;
            before->next = prev;

            before = after;
            after = curr;


        }

        return NULL;
    }
};