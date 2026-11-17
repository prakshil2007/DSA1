#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertEnd(struct Node *head, int value) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    if (n == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n->data = value;
    n->next = NULL;

    if (head == NULL)
        return n;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    return head;
}

/* a. delete from the beginning */
struct Node *deleteBegin(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    head = head->next;
    printf("Deleted %d\n", temp->data);
    free(temp);
    return head;
}

/* b. delete from the end */
struct Node *deleteEnd(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        printf("Deleted %d\n", head->data);
        free(head);
        return NULL;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

/* c. delete from the middle (node is searched by its value) */
struct Node *deleteMiddle(struct Node *head, int key) {
    struct Node *prev = NULL, *curr = head;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node with value %d not found.\n", key);
        return head;
    }

    if (prev == NULL)
        head = head->next;
    else
        prev->next = curr->next;

    printf("Deleted %d\n", curr->data);
    free(curr);
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
    int choice, value;

    do {
        printf("\n1. Insert at the end (to build the list)\n");
        printf("2. Delete from the beginning\n");
        printf("3. Delete from the end\n");
        printf("4. Delete from the middle\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;
            case 2:
                head = deleteBegin(head);
                break;
            case 3:
                head = deleteEnd(head);
                break;
            case 4:
                printf("Enter value of the node to delete: ");
                scanf("%d", &value);
                head = deleteMiddle(head, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
} 