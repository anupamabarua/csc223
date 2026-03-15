#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    heap[size] = value;
    int i = size;
    size++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i] > heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else {
            break;
        }
    }

    printf("Inserted %d\n", value);
}

int removeMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int max = heap[0];

    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while (1) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else {
            break;
        }
    }

    return max;
}

void printHeap() {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap: ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    printf("Max (top): %d\n", heap[0]);
}

int main() {
    int choice, value;

    printf("=== Max Heap Program ===\n");

    while (1) {
        printf("\n1. Insert\n2. Remove Max\n3. Print Heap\n4. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
        } else if (choice == 2) {
            int max = removeMax();
            if (max != -1)
                printf("Removed max: %d\n", max);
        } else if (choice == 3) {
            printHeap();
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
