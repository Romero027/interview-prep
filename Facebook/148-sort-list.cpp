/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if( !head || !head->next ) 
            return head;
        
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while( fast != nullptr && fast->next != nullptr ) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* newList = new ListNode(-1);
        ListNode* temp = newList;
        
        while( left && right ) {
            if(left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next; 
            }
            temp = temp->next;
        }
        if( left ) {
            temp->next = left;
        }
        if( right ) {
            temp->next = right;
        }
        
        
        
        return newList->next;
    } 
    
};
