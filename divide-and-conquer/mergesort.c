#include<stdio.h>
#include<malloc.h>

void merge(int *arr, int low, int mid, int high) {
    int index = 0;
    int left = low, right = mid+1;
    int *temp = (int *) malloc (sizeof(int) * (high-low+1));
    
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])    temp[index++] = arr[left++];
        else    temp[index++] = arr[right++];
    }

    while (left <= mid) {
        temp[index++] = arr[left++];
    }

    while (right <= high) {
        temp[index++] = arr[right++];
    }

    index = 0;
    while (low <= high) arr[low++] = temp[index++];

    free(temp);
}

void mergeSort(int *arr, int low, int high) {
    int mid;
    if (low < high)  {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void display (int *arr, int size) {
    int i;
    for (i=0; i<size; ++i) {
        printf("%d ", arr[i]);
    }
}

int main () {
    int n, i;
    int *arr;

    printf("Enter size of list: ");
    scanf("%d", &n);

    arr = (int *) malloc (sizeof(int) * n);

    for (i=0; i<n; ++i) {
        printf("Enter value at %d position: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEntered list: ");
    display(arr, n);

    mergeSort(arr, 0, n-1);

    printf("\nSorted list: ");
    display(arr, n);

    free(arr);

    return 0;
}