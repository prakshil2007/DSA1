#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
	stack[++top] = x;
}

int pop(void) {
	return stack[top--];
}

int evaluate(char exp[]) {
	char *token = strtok(exp, " \n");

	while (token != NULL) {
		if (isdigit((unsigned char)token[0]) ||
			(token[0] == '-' && isdigit((unsigned char)token[1]))) {
			push(atoi(token));
		} else {
			int b = pop();
			int a = pop();

			switch (token[0]) {
				case '+': push(a + b); break;
				case '-': push(a - b); break;
				case '*': push(a * b); break;
				case '/': push(a / b); break;
			}
		}
		token = strtok(NULL, " \n");
	}

	return pop();
}

int main(void) {
	char exp[MAX];

	printf("Enter postfix expression (separate tokens by space): ");
	fgets(exp, MAX, stdin);
	printf("Result = %d\n", evaluate(exp));
	return 0;
}