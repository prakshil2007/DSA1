#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

int isEmpty() { 
    return front == NULL; 
}

void enqueue(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (isEmpty())
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted\n", x);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node *temp = front;
    printf("%d deleted\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;         // queue became empty
    free(temp);
}

void frontElement() {
    if (isEmpty()) printf("Queue is empty\n");
    else printf("Front: %d\n", front->data);
}

void rearElement() {
    if (isEmpty()) printf("Queue is empty\n");
    else printf("Rear: %d\n", rear->data);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Front 4.Rear 5.Display 6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2: dequeue();      break;
            case 3: frontElement(); break;
            case 4: rearElement();  break;
            case 5: display();      break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}