#include <stdio.h>
void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1= m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for (i=0;i<n1;i++)
        L[i]=arr[i+l];
    for (j=0;j<n2;j++)
        R[j]=arr[j+m+1];
    i=j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
    k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int l,int r){
    if(l<r) {
        int m= l+((r-l)/2);
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
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
    merge_sort(array,0,size-1);
    printf("Sorted array: ");
    display(array, size);
    return 0;
}
