#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node** head, int v) {
    struct Node* newNode = createNode(v);
    struct Node* tmp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while(tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}
void printList(struct Node* head) {
    struct Node* tmp = head;
    while(tmp != NULL) {
        printf("%d -> ", tmp -> vertex);
        tmp = tmp -> next;
    }
}
int main() {
    struct Node* head = NULL;
    insertNode(&head,10);
    insertNode(&head,20);
    insertNode(&head,30);
    printList(head);
    return 0;
}
