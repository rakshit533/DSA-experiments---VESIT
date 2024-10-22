#include <stdio.h>
#include <stdlib.h>

typedef struct Song {
    int id;
    char title[50];
    struct Song* next;
} Song;

typedef struct Queue {
    Song* front;
    Song* rear;
} Queue;

Song* createSong(int id, char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    newSong->id = id;

    for (int i = 0; title[i] != '\0' && i < 49; i++){
        newSong->title[i] = title[i];
    }
    newSong->title[49] = '\0';
    newSong->next = NULL;
    return newSong;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int id, char* title) {
    Song* newSong = createSong(id, title);
    if (q->rear == NULL) {
        q->front = q->rear = newSong;
        return;
    }
    q->rear->next = newSong;
    q->rear = newSong;
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Song* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Song* temp = q->front;
    while (temp != NULL) {
        printf("Song ID: %d, Title: %s", temp->id, temp->title);
        temp = temp->next;
    }
}

int main() {
    Queue* q = createQueue();
    int choice, id;
    char title[50];

    while (1) {
        printf("\nMusic Player Menu:\n");
        printf("\n 1. Add Song");
        printf("\n 2. Remove Song");
        printf("\n 3. Display Songs");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song ID: ");
                scanf("%d", &id);
                printf("Enter song title: ");
                scanf(" %[^\n]%*c", title);
                enqueue(q, id, title);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
