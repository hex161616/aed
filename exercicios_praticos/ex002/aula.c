#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    struct ListNode *atual = head;
    struct ListNode *anterior = head;

    for (int i = 0; i < k; i++) {
        atual->next;
        if (atual++ == '\0') {
            anterior = atual;
        }
    }
    return anterior;
}