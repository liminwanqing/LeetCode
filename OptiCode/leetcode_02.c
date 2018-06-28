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
    struct ListNode *ans = (struct ListNode*)malloc(sizeof(struct ListNode)), *tail = ans;   //空的头结点  
    int s_val = 0;  //进位  
    for (; l1 && l2; l1 = l1->next, l2 = l2->next){ //处理两条链公共长度部分  
        int sum = l1->val + l2->val + s_val;    //计算当前和  
        if (sum > 9){   //处理进位  
            sum -= 10;  
            s_val = 1;  
        }  
        else{  
            s_val = 0;  
        }  
        //分配结点  
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));  
        tail = tail->next;  
        tail->val = sum;  
    }  
    //取两条链长的那条剩下的部分  
    l1 = l1 ? l1 : l2;  
    //遍历剩余部分  
    for( ; l1; l1 = l1->next){  
        //加上进位计算结点值  
        int sum = l1->val + s_val;  
        if (sum > 9){  
            sum -= 10;  
            s_val = 1;  
        }  
        else {  
            s_val = 0;  
        }  
        //分配结点  
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));  
        tail = tail->next;  
        tail->val = sum;  
    }  
    //如果最后还有进位，再分配一个结点  
    if (s_val){  
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));  
        tail = tail->next;  
        tail->val = 1;  //加法的进位只可能是1  
    }  
    tail->next = NULL;  //将链表收尾  
    //将空的头结点释放，从第二个结点返回  
    tail = ans;  
    ans = ans->next;  
    free(tail);  
    return ans;  
    
}
