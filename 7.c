#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void displayForward() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Forward Traversal: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void displayBackward() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }


    while(temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward Traversal: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}


int main() {

    displayForward();
    displayBackward();

    return 0;
}