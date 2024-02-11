#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if the stack is full
bool isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int data) {
    if (isFull()) {
        printf("Stack is Overflow.\n");
    } else {
        stack[++top] = data;
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is Underflow.\n");
        return -1; // Return a sentinel value
    } else {
        return stack[top--];
    }
}

// Function to get the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
        return -1; // Return a sentinel value
    } else {
        return stack[top];
    }
}

int main() {
    int n, element;

    printf("Enter the number of elements for the stack: ");
    scanf("%d", &n);

    printf("Enter %d integer elements for the stack:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        push(element);
    }

    printf("Top element: %d\n", peek());

    printf("Popped elements: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");

    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is stack full? %s\n", isFull() ? "Yes" : "No");

    return 0;
}
