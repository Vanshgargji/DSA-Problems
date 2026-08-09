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
        if(!head || !head->next) return head;

        priority_queue<int, vector<int>, greater<int>> pq; // mean heap

        ListNode *temp = head;

        while(temp){
            pq.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(!pq.empty()){
            int value = pq.top();
            pq.pop();

            temp->val = value;
            temp = temp->next;
        }

        return head;
    }
};