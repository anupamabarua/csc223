#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heap_size = 0;  


void swap(a, b)
    int *a;
    int *b;
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}


void insert(value)
    int value;
{
    int i;
    int parent;

    if (heap_size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    heap[heap_size] = value;
    i = heap_size;
    heap_size++;

    while (i > 0) {
        parent = (i - 1) / 2;
        if (heap[i] > heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else {
            break;
        }
    }

    printf("Inserted %d\n", value);
}


int removeMax()
{
    int max;
    int i;
    int left, right, largest;

    if (heap_size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    max        = heap[0];
    heap[0]    = heap[heap_size - 1];
    heap_size--;

    /* sift down */
    i = 0;
    for (;;) {
        left    = 2 * i + 1;
        right   = 2 * i + 2;
        largest = i;

        if (left  < heap_size && heap[left]  > heap[largest])
            largest = left;
        if (right < heap_size && heap[right] > heap[largest])
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


void printHeap()
{
    int i;

    if (heap_size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap array: ");
    for (i = 0; i < heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    printf("Max (root): %d\n", heap[0]);
}


int main()
{
    int choice;
    int value;
    int max;

    printf("=== Max Heap Program ===\n");

    for (;;) {
        printf("\n1. Insert\n2. Remove Max\n3. Print Heap\n4. Quit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
        } else if (choice == 2) {
            max = removeMax();
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