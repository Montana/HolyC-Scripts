#include "Syscalls.h"

#define MAX_SIZE 100

struct Heap {
    I64 data[MAX_SIZE];
    I64 size;
};

U0 Swap(I64 *a, I64 *b) {
    I64 temp = *a;
    *a = *b;
    *b = temp;
}

U0 Heapify(struct Heap *heap, I64 idx) {
    I64 largest = idx;
    I64 left = 2 * idx + 1;
    I64 right = 2 * idx + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }

    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }

    if (largest != idx) {
        Swap(&heap->data[idx], &heap->data[largest]);
        Heapify(heap, largest);
    }
}

U0 BuildHeap(struct Heap *heap) {
    for (I64 i = heap->size / 2 - 1; i >= 0; i--) {
        Heapify(heap, i);
    }
}

U0 Insert(struct Heap *heap, I64 key) {
    if (heap->size == MAX_SIZE) return;
    heap->size++;
    I64 i = heap->size - 1;
    heap->data[i] = key;

    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        Swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

I64 ExtractMax(struct Heap *heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    I64 root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    Heapify(heap, 0);

    return root;
}

U0 PrintHeap(struct Heap *heap) {
    for (I64 i = 0; i < heap->size; i++) {
        PrintF("%d ", heap->data[i]);
    }
    Print("\n");
}

U0 Main() {
    struct Heap heap;
    heap.size = 0;

    Insert(&heap, 3);
    Insert(&heap, 2);
    Insert(&heap, 15);
    Insert(&heap, 5);
    Insert(&heap, 4);
    Insert(&heap, 45);

    PrintHeap(&heap);

    PrintF("Max: %d\n", ExtractMax(&heap));
    PrintHeap(&heap);
}
