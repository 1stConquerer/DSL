#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert at beginning
void insertFront(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {  // empty
        front = rear = 0;
    } 
    else if (front == 0) {
        front = MAX - 1;
    } 
    else {
        front--;
    }

    deque[front] = x;
    printf("Inserted %d at beginning\n", x);
}

// Delete from end
void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear) { // only one element
        front = rear = -1;
    } 
    else if (rear == 0) {
        rear = MAX - 1;
    } 
    else {
        rear--;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                deleteRear();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}