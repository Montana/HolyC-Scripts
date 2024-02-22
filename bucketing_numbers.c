#include "Syscalls.h"

U0 Main() {
    I64 numbers[] = {45, 150, 23, 199, 245, 99, 100, 205, 0, 299};
    I64 count = sizeof(numbers) / sizeof(numbers[0]);
    I64 bucket1[10], bucket2[10], bucket3[10];
    I64 idx1 = 0, idx2 = 0, idx3 = 0, i;

    for (i = 0; i < count; i++) {
        if (numbers[i] >= 0 && numbers[i] <= 99) {
            bucket1[idx1++] = numbers[i];
        } else if (numbers[i] >= 100 && numbers[i] <= 199) {
            bucket2[idx2++] = numbers[i];
        } else if (numbers[i] >= 200 && numbers[i] <= 299) {
            bucket3[idx3++] = numbers[i];
        }
    }

    Print("Bucket 1 (0-99): ");
    for (i = 0; i < idx1; i++) PrintF("%d ", bucket1[i]);
    Print("\n");

    Print("Bucket 2 (100-199): ");
    for (i = 0; i < idx2; i++) PrintF("%d ", bucket2[i]);
    Print("\n");

    Print("Bucket 3 (200-299): ");
    for (i = 0; i < idx3; i++) PrintF("%d ", bucket3[i]);
    Print("\n");
}
