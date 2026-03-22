#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


void deleteBegin() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;


    if(head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
    printf("Node deleted from beginning\n");
}


void deleteEnd() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

  
    if(head->next == NULL) {
        head = NULL;
        free(temp);
        printf("Only node deleted\n");
        return;
    }

   
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);

    printf("Node deleted from end\n");
}


void deleteAtPosition() {
    struct Node *temp;
    int pos, i;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }

    // Delete first node
    if(pos == 1) {
        deleteBegin();
        return;
    }

    temp = head;

    for(i = 1; i < pos; i++) {
        temp = temp->next;

        if(temp == NULL) {
            printf("Invalid position\n");
            return;
        }
    }

    // If last node
    if(temp->next == NULL) {
        temp->prev->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted from position %d\n", pos);
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
    
    deleteBegin();
    deleteEnd();
    deleteAtPosition();
    display();

    return 0;
}