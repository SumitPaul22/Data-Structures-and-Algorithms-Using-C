#include <stdio.h>
void insertion_sort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++) {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void display(int arr[],int n){
    for (int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
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
    insertion_sort(array, size);
    printf("Sorted array: ");
    display(array, size);
    return 0;
}
