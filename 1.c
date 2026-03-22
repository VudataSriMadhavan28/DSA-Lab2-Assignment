#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void create() {
    int choice = 1;
    struct Node *newNode, *temp;

    while(choice == 1) {
       
        newNode = (struct Node*)malloc(sizeof(struct Node));

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

    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    create();  
    display();

    return 0;
}