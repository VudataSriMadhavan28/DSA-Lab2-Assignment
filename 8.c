#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at Beginning
void insertBegin() {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    printf("Node inserted at beginning\n");
}

// Insert at End
void insertEnd() {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted at end\n");
}

// Insert at Given Position
void insertAtPosition() {
    struct Node *newNode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1) {
        insertBegin();
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    temp = head;

    for(i = 1; i < pos - 1; i++) {
        if(temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("Node inserted at position %d\n", pos);
}

// Display (for checking)
void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    insertBegin();
    insertEnd();
    insertAtPosition();
    display();

    return 0;
}