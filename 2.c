#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void create() {
    int choice = 1;
    struct Node *newNode, *temp = NULL;  // FIX: initialize temp

    while(choice == 1) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } 
        else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Press 1 to continue, 0 to stop: ");
        scanf("%d", &choice);
    }
}


void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int countNodes() {
    struct Node *temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int total;

    create();
    display();

    total = countNodes();
    printf("Total number of nodes: %d\n", total);

    return 0;
}