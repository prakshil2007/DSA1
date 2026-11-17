#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;
    return n;
}

/* a. insert at the front of the list */
struct Node* insertFront(struct Node *head, int value) {
    struct Node *n = createNode(value);
    n->next = head;
    return n;
}

/* b. insert after a given node (node is searched by its value) */
struct Node* insertAfter(struct Node *head, int key, int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return head;
    }

    struct Node *n = createNode(value);
    n->next = temp->next;
    temp->next = n;
    return head;
}

/* c. insert at the end of the list */
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *n = createNode(value);
    struct Node *temp = head;

    if (head == NULL)
        return n;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    return head;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" => ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, key;

    do {
        printf("\n1. Insert at the front\n2. Insert after a given node\n");
        printf("3. Insert at the end\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertFront(head, value);
                break;

            case 2:
                printf("Insert after which node value: ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &value);
                head = insertAfter(head, key, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
} 