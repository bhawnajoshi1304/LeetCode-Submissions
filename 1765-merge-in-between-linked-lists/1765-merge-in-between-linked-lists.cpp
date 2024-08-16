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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* prev=list1;
        ListNode* curr1=list1;
        ListNode* temp=list2;
        int i=1;
        while(i!=a){
            prev=prev->next;
            i++;
        }
        curr1 = prev->next;
        while (i <= b) {
            curr1 = curr1->next;
            i++;
        }
        while(temp->next!=NULL){
            temp=temp->next;
        }
        prev->next=list2;
        temp->next=curr1;
        curr1=NULL;

        return list1;
    }
};