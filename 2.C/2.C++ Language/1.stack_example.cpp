#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int val) {
    if(top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if(top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack: ");
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10); push(20); push(30);
    display();
    pop();
    display();
    return 0;
}
#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int val) {
    if(top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if(top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack: ");
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10); push(20); push(30);
    display();
    pop();
    display();
    return 0;
}
