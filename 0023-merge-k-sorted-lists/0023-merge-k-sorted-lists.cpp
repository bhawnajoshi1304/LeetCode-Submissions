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
    void swapLists(vector<ListNode*>& list, int idx) {
        list[idx] = list[idx]->next;
        if (list[idx] == NULL)
            list.erase(list.begin() + idx);
    }
    int findMin(vector<ListNode*>& lists) {
        int f = -1;
        for (int i = 0; i < lists.size(); i++) {
            if (!lists[i])
                continue;
            if (f == -1 || lists[i]->val < lists[f]->val) {
                f = i;
            }
        }
        return f;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        int idx = findMin(lists);
        if (idx == -1)
            return NULL;
        ListNode* node = lists[idx];
        swapLists(lists, idx);
        node->next = mergeKLists(lists);
        return node;
    }
};