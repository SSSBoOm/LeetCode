/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    int val1 = 0, val2 = 0, sum;
    struct ListNode* Output = NULL;
    struct ListNode* ptr = NULL;
    while(l1 != NULL || l2 != NULL || carry != 0) {
        val1 = 0, val2 = 0, sum = 0;
        if(l1 != NULL) {
            val1 = l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL) {
            val2 = l2->val;
            l2 = l2->next;
        }

        sum = carry + val1 + val2;
        carry = sum / 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
                
        if(Output == NULL) {
            Output = newNode;
            ptr = newNode;
        }
        else {
            ptr->next = newNode;
            ptr = ptr->next;
        }
    }
    return Output;
}