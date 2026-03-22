#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
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
    head = head->next;
    free(temp);

    printf("Node deleted from beginning\n");
}


void deleteEnd() {
    struct Node *temp, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }


    if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Only node deleted\n");
        return;
    }

    temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Node deleted from end\n");
}


void deleteAtPosition() {
    struct Node *temp, *prev;
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


    if(pos == 1) {
        deleteBegin();
        return;
    }

    temp = head;

    for(i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;

        if(temp == NULL) {
            printf("Invalid position\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted from position %d\n", pos);
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
  

    deleteBegin();
    deleteEnd();
    deleteAtPosition();

    display();

    return 0;
}