#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


void reverseDLL() {
    struct Node *temp = NULL;
    struct Node *current = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(current != NULL) {
   
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        
        current = current->prev;
    }


    if(temp != NULL) {
        head = temp->prev;
    }

    printf("Doubly Linked List reversed successfully\n");
}


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


int main() {
   

    reverseDLL();
    display();

    return 0;
}