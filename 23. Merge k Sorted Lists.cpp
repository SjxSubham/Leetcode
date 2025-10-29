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
        ListNode* res = new ListNode(0);
        ListNode* temp = res;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto l : lists) {
            while (l != nullptr) {
                minHeap.push(l->val);
                l = l->next;
            }
        }

        while (!minHeap.empty()) {
            int num = minHeap.top();
            minHeap.pop();

            temp->next = new ListNode(num);
            temp = temp->next;
        }

        return res->next;
    }
};