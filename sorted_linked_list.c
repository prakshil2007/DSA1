#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main(void) {
    int n, m, value;
    int swap;
    int merged = 0;
    int status = EXIT_FAILURE;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *tail1 = NULL;
    struct Node *tail2 = NULL;
    struct Node *newnode;
    struct Node *current;
    struct Node *index;
    struct Node *temp;

    printf("Enter number of nodes for first list: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of nodes.\n");
        goto cleanup;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value of node %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid value.\n");
            goto cleanup;
        }

        newnode = malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            goto cleanup;
        }

        newnode->data = value;
        newnode->next = NULL;

        if (head1 == NULL) {
            head1 = newnode;
            tail1 = newnode;
        } else {
            tail1->next = newnode;
            tail1 = newnode;
        }
    }

    printf("Enter number of nodes for second list: ");
    if (scanf("%d", &m) != 1 || m < 0) {
        printf("Invalid number of nodes.\n");
        goto cleanup;
    }

    for (int i = 0; i < m; i++) {
        printf("Enter value of node %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid value.\n");
            goto cleanup;
        }

        newnode = malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            goto cleanup;
        }

        newnode->data = value;
        newnode->next = NULL;

        if (head2 == NULL) {
            head2 = newnode;
            tail2 = newnode;
        } else {
            tail2->next = newnode;
            tail2 = newnode;
        }
    }

    /* Merge the two lists, including the case where either list is empty. */
    if (head1 == NULL) {
        head1 = head2;
    } else {
        tail1->next = head2;
    }
    merged = 1;

    /* Sort the merged list in ascending order. */
    for (current = head1; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                swap = current->data;
                current->data = index->data;
                index->data = swap;
            }
        }
    }

    printf("Sorted list: ");
    for (temp = head1; temp != NULL; temp = temp->next) {
        printf("%d -> ", temp->data);
    }
    printf("NULL\n");
    status = EXIT_SUCCESS;

cleanup:
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }

    if (!merged) {
        while (head2 != NULL) {
            temp = head2;
            head2 = head2->next;
            free(temp);
        }
    }

    return status;
}