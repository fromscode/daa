#include<stdio.h>
#include<malloc.h>

int binarySearch(int *arr, int left, int right, int key) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        } 
        else if (arr[mid] > key) {
            return binarySearch(arr, left, mid-1, key);
        }
        else {
            return binarySearch(arr, mid+1, right, key);
        }
    } 
    else {
        return -1;
    }
}

int main () {
    int n, key, i, res;
    int *arr;

    printf("Enter size of list: ");
    scanf("%d", &n);

    arr = (int *) malloc (sizeof(int) * n);

    printf("\nThe subsequent values should be entered in sorted order for binary search to work\n\n");
    for (i=0; i<n; ++i) {
        printf("Enter value at %d position: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to be searched: ");
    scanf("%d", &key);

    res = binarySearch(arr, 0, n-1, key);
    
    if (res == -1) {
        printf("Element %d not found", key);
    }
    else {
        printf("Element %d found at %d position", key, res+1);
    }

    free(arr);

    return 0;
}