// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     void swapLists(vector<ListNode*>& list, int idx) {
//         list[idx] = list[idx]->next;
//         if (list[idx] == NULL)
//             list.erase(list.begin() + idx);
//     }
//     int findMin(vector<ListNode*>& lists) {
//         int f = -1;
//         for (int i = 0; i < lists.size(); i++) {
//             if (!lists[i])
//                 continue;
//             if (f == -1 || lists[i]->val < lists[f]->val) {
//                 f = i;
//             }
//         }
//         return f;
//     }

//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int idx = findMin(lists);
//         if (idx == -1) return NULL;
//         ListNode* node = lists[idx];
//         swapLists(lists, idx);
//         node->next = mergeKLists(lists);
//         return node;
//     }
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            function<bool(ListNode*, ListNode*)>
        > pq([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        });

        for (auto node : lists)
            if (node) pq.push(node);

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = tail->next;

            if (cur->next)
                pq.push(cur->next);
        }

        return dummy.next;
    }
};
