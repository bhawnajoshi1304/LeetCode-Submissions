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
     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return {-1, -1};
        }
        ListNode* temp = head->next;
        ListNode* prev = head;
        int mini = INT_MAX;
        int count = 2, fp = -1, lp = -1;

        while(temp->next != NULL){
            if((temp->val > prev->val && temp->val > temp->next->val) || (temp->val < prev->val && temp->val < temp->next->val)){
                if(fp == -1){
                    fp = count;
                }
                if(lp != -1){
                    mini = min(count-lp, mini);
                }
                lp = count;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }   

        if(fp == -1 || fp == lp){
            return {-1, -1};
        }

        int maxi = -1;
        maxi = max(maxi, lp-fp);

        return {mini, maxi};
    }
};