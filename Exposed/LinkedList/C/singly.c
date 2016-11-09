
#include <stdio.h>
#include <stdlib.h>

// C doesn't have generics, use int!
typedef struct Node {
    struct Node *next;
    int value;
} Node;

void print(Node * head) {
    Node *ptr = head;
    printf ("HEAD->");
    while (ptr != NULL) {
        printf("%d->", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void add_to_head(Node **head, int value) {
    Node * node = NULL;
    node = malloc(sizeof(Node));
    if (node != NULL) {
        node->value = value;
        node->next = *head;
        *head = node;
    }
}

void remove_from_head(Node **head) {
    if (head == NULL || *head == NULL) {
        return;
    }
    Node *ptr = *head;
    *head = (*head)->next;
    free (ptr);
}

int main() {
    Node * head = NULL;
    /*head = malloc(sizeof(Node));
    if (head == NULL) {
        return 1;
    }
    head->value = 1;
    head->next = NULL;
    */
    add_to_head(&head, 3);
    add_to_head(&head, 4);
    print(head);
    remove_from_head(&head);
    print(head);
    remove_from_head(&head);
    print(head);
    remove_from_head(&head);
    print(head);
}
