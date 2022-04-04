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
    void swap(ListNode* a, ListNode* b){
        int tmp=a->val;
        a->val=b->val;
        b->val=tmp;
    }
    ListNode* kthNode(ListNode* head, int k){
        while(--k)
            head=head->next;
        return head;
    }
    int lengthLinkedList(ListNode* head){
        int n=0;
        while(head!=NULL){
            n+=1;
            head=head->next;
        }
        // cout<<n<<"\n";
        return n;
    }
    ListNode* kthFromEnd(ListNode* head,int k){
        int n=lengthLinkedList(head);
        n-=k;
        while(n--){
            head=head->next;
        }
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        swap(kthNode(head,k),kthFromEnd(head,k));
        return head;
    }
};