#include<stdio.h>
#include<malloc.h>

int linearSearch(int *arr, int size, int key) {
    int i;

    for (i=0; i<size; ++i) {
        if (arr[i] == key)  return i;
    }

    return -1;
}

int main () {
    int n, i, key, res;
    int *arr;

    printf("Enter size of list: ");
    scanf("%d", &n);

    arr = (int *) malloc (sizeof(int) * n);
    for (i=0; i<n; ++i) {
        printf("Enter value at %d position: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    res = linearSearch(arr, n, key);

    if (res == -1) {
        printf("Element %d not found", key);
    }
    else {
        printf("Element %d found at %d position", key, res+1);
    }

    return 0;
}