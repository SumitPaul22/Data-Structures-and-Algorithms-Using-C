#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int array[], int size) {
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(&array[i], &array[min_index]);
    }
}
void display(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter %d values for the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Original array: ");
    display(array, size);
    selection_sort(array, size);
    printf("Sorted array: ");
    display(array, size);
    return 0;
}
