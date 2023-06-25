/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* head = NULL;
    struct ListNode* ptr;
    while(list1 != NULL || list2 != NULL) {
        if(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                struct ListNode* newNode = malloc(sizeof(struct ListNode));
                newNode->val = list1->val;
                newNode->next = NULL;
                if(head == NULL) {
                    head = newNode;
                    ptr = newNode;
                }
                else {
                    ptr->next = newNode;
                    ptr = ptr->next;
                }
                list1 = list1->next;
            }
            else {
                struct ListNode* newNode = malloc(sizeof(struct ListNode));
                newNode->val = list2->val;
                newNode->next = NULL;
                if(head == NULL) {
                    head = newNode;
                    ptr = newNode;
                }
                else {
                    ptr->next = newNode;
                    ptr = ptr->next;
                }
                list2 = list2->next;
            }
        }
        else if(list1 == NULL && list2 != NULL) {
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = list2->val;
            newNode->next = NULL;
            if(head == NULL) {
                head = newNode;
                ptr = newNode;
            }
            else {
                ptr->next = newNode;
                ptr = ptr->next;
            }
            list2 = list2->next;
        }
        else if(list1 != NULL && list2 == NULL) {
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = list1->val;
            newNode->next = NULL;
            if(head == NULL) {
                head = newNode;
                ptr = newNode;
            }
            else {
                ptr->next = newNode;
                ptr = ptr->next;
            }
            list1 = list1->next;
        }
    }
    return head;
}