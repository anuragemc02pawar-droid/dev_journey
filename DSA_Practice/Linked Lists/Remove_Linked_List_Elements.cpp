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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;

        ListNode* node=head;
        ListNode* prev=NULL;
        
        while(node!=NULL){
            ListNode* front=node->next;
            if(node->val==val){
                node->next=NULL;
                if(prev!=NULL){
                    prev->next=front;
                }else{
                    head=front;
                }
            }else{
                prev=node;
            }
            node=front;
        }
        return head;

    }
};