#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


void create() {
    int choice = 1;
    struct Node *newNode, *temp = NULL;

    while(choice == 1) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->prev = NULL;
        newNode->next = NULL;

        // First node
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } 
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }

        printf("Press 1 to continue, 0 to stop: ");
        scanf("%d", &choice);
    }
}

// Display (Forward Traversal - optional for checking)
void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Function
int main() {
    create();   // Calling create function
    display();  // Optional

    return 0;
}