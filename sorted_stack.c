#include <stdio.h>
#define MAX 50

int stack[MAX];
int topIndex = -1;

/* only these four operations are used to sort the stack */
int isEmpty() {
    return topIndex == -1;
}

int top() {
    return stack[topIndex];
}

void push(int x) {
    stack[++topIndex] = x;
}

int pop() {
    return stack[topIndex--];
}

/* insert x into the (sorted) stack at its correct place */
void insertSorted(int x) {
    int t;

    if (isEmpty() || x >= top()) {
        push(x);
        return;
    }

    t = pop();
    insertSorted(x);
    push(t);
}

/* sort the stack: remove all elements, then insert them back in order */
void sortStack() {
    int x;

    if (isEmpty())
        return;

    x = pop();
    sortStack();
    insertSorted(x);
}

/* helpers written with recursion too, so that no loop is used anywhere */
void readStack(int n) {
    int x;

    if (n == 0)
        return;

    scanf("%d", &x);
    push(x);
    readStack(n - 1);
}

void printStack() {
    int x;

    if (isEmpty())
        return;

    x = pop();
    printf("%d ", x);
    printStack();
    push(x);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    readStack(n);

    printf("\nStack before sorting (top to bottom): ");
    printStack();

    sortStack();

    printf("\nStack after sorting  (top to bottom): ");
    printStack();

    printf("\n");
    return 0;
} 