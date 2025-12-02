#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if ( head == NULL || head->next == NULL || k == 0 ) {
        return head;
    }
    

    struct ListNode *atual = head;
    int len = 1;
    while ( atual->next ) {
        atual = atual->next;
        len++;
    }


    k = k % len;
    if ( k == 0 ) {
        return head;  
    }

    atual->next = head;

    int passos_novo_final = len - k - 1;
    struct ListNode *novo_final = head;
    for ( int i = 0; i < passos_novo_final; i++ ) {
        novo_final = novo_final->next;
    }

    struct ListNode *novo_head = novo_final->next;

    novo_final->next = NULL;

    return novo_head;
}

int main() {
    return 0;
}