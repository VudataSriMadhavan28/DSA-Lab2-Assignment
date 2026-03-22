#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void reverseList() {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(curr != NULL) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;
        curr = next;        
    }

    head = prev; 
    printf("List reversed successfully\n");
}


void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    // Assume list already created

    reverseList();
    display();

    return 0;
}