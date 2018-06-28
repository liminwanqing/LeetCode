 /**
 * 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

 * 示例：

 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag = 0;
    
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* reshead = res;
    res->next = NULL;
    while ( l1 != NULL || l2 != NULL) {
        
        if (res == NULL) {
            return reshead;
        }
       if (l1 == NULL) {
           if ((flag + l2->val) >= 10) {
                res->val = flag + l2->val - 10;
                flag = (flag + l2->val)/10;
            } else {
                res->val = flag + l2->val;
               flag = 0;
            }
           l2 = l2->next;
            if (l2 != NULL || flag!=0 ) {
                res->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                res = res->next;
                res->val = flag;
                res->next = NULL;
            }
           continue;
       } else if (l2 == NULL) {
           if ((flag + l1->val) >= 10) {
                res->val = flag + l1->val - 10;
                flag = (flag + l1->val)/10;
            } else {
                res->val = flag + l1->val;
               flag = 0;
            }
           
           l1 = l1->next;
            if (l1 != NULL || flag!=0) {
                res->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                res = res->next;
                res->val = flag;
                res->next = NULL;
            }
           continue;
           
       } else {
           if ((flag + l1->val + l2->val) >= 10) {
                res->val = flag + l1->val + l2->val - 10;
                flag = (flag + l1->val + l2->val)/10;
            } else {
                res->val = flag + l1->val + l2->val;
               flag = 0;
            }
           
           l1 = l1->next;
           l2 = l2->next;

            if (l1 != NULL || l2 != NULL || flag!=0) {
                res->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                res = res->next;
                res->val = flag;
                res->next = NULL;
            }
        }
        
        
    }


    return reshead;
    
}
