#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL){
        newNode->next = newNode;
        head = newNode;
    }else{
        struct Node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL){
        newNode->next = newNode;
        head = newNode;
    }else{
        struct Node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
}

void insertAtPosition(int value, int position){
    if (position < 1){
        printf("Position should be >= 1\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1){
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++){
        if (temp->next == head){
            printf("Position is out of range\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning()
{
    if (head == NULL){
        printf("List is empty\n");
        return;
    }

    if (head->next == head){
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        struct Node *toDelete = head;
        temp->next = head->next;
        head = head->next;
        free(toDelete);
    }
}

void deleteFromEnd(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }

    if (head->next == head){
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        struct Node *toDelete;

        while (temp->next->next != head){
            temp = temp->next;
        }

        toDelete = temp->next;
        temp->next = head;
        free(toDelete);
    }
}

void deleteFromPosition(int position){
    if (position < 1){
        printf("Position should be >= 1\n");
        return;
    }

    if (head == NULL){
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++){
        if (temp->next == head){
            printf("Position is out of range\n");
            return;
        }
        temp = temp->next;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void display(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    insertAtPosition(15, 3);
    display();

    deleteFromBeginning();
    display();

    deleteFromEnd();
    display();

    deleteFromPosition(2);
    display();

    return 0;
}
