#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
	stack[++top] = c;
}

char pop(void) {
	return stack[top--];
}

int isMatching(char open, char close) {
	return (open == '(' && close == ')') ||
		   (open == '{' && close == '}') ||
		   (open == '[' && close == ']');
}

int isBalanced(char exp[]) {
	top = -1;

	for (int i = 0; exp[i] != '\0'; i++) {
		char ch = exp[i];

		if (ch == '(' || ch == '{' || ch == '[') {
			push(ch);
		} else if (ch == ')' || ch == '}' || ch == ']') {
			if (top == -1 || !isMatching(pop(), ch)) {
				return 0;
			}
		}
	}

	/* The stack must be empty at the end. */
	return top == -1;
}

int main(void) {
	char exp[MAX];

	printf("Enter an expression: ");
	scanf("%99s", exp);

	if (isBalanced(exp)) {
		printf("Balanced\n");
	} else {
		printf("Not Balanced\n");
	}

	return 0;
}