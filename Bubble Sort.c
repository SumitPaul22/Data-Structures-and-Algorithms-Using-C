#include <stdio.h>
void swap(int*a,int*b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int arr[],int n){
    int i,j,swapped;
    for(i=0;i<n-1;i++) {
        swapped=0;
        for(j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0) {
            break;
        }
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
    bubble_sort(array, size);
    printf("Sorted array: ");
    display(array, size);
    return 0;
}
