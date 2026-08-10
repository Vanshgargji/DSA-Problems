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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap
        priority_queue<
        pair<int, ListNode*>, 
        vector<pair<int, ListNode*>>, 
        greater<pair<int, ListNode*>>
        > pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while(!pq.empty()){
            int val = pq.top().first;
            ListNode *node = pq.top().second;
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next){
                pq.push({node->next->val, node->next});
            }

        }

        return dummy->next;
    }
};