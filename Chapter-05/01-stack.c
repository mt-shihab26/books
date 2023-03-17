#include <stdio.h>

#define STACK_MAX 100

typedef struct {
    int top;
    int data[STACK_MAX];
} Stack;

void push(Stack * s, int item) {
    if (s->top >= STACK_MAX) {
        printf("Stack is full!\n");
        return;
    }
    s->data[s->top] = item;
    s->top++;
}

int pop(Stack *s) {
    if (s->top == 0) {
        printf("Stack is empty! ");
        return -1;
    }
    else {
        s->top--;
        return s->data[s->top];
    }
}

int main(void) {
    Stack my_stack;
    my_stack.top = 0;

    push(&my_stack, 1);
    push(&my_stack, 5);
    push(&my_stack, 8);

    printf("%d\n", pop(&my_stack)); // 1
    printf("%d\n", pop(&my_stack)); // 5
    printf("%d\n", pop(&my_stack)); // 8
    printf("%d\n", pop(&my_stack)); // stack is empty
}