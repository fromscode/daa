#include<stdio.h>
#include<malloc.h>

int partition(int *arr, int low, int high) {
    int temp;
    int left = low, right = high;
    int pivot = arr[low];

    while (left < right) {
        while (left<high && arr[left] <= pivot)  ++left;

        while (right>low && arr[right] > pivot) --right;

        if (left < right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    temp = arr[right];
    arr[right] = arr[low];
    arr[low] = temp;

    return right;
}

void quickSort(int *arr, int low, int high) {
    int part;
    if (low <= high) {
        part = partition(arr, low, high);
        quickSort(arr, low, part-1);
        quickSort(arr, part+1, high);
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

    quickSort(arr, 0, n-1);

    printf("\nSorted list: ");
    display(arr, n);

    free(arr);

    return 0;
}