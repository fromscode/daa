#include<stdio.h>
#include<malloc.h>

void swapi (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapf (float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int* id, float* profit, float* weight, float* ppw, int low, int high) {
    int left = low, right = high;
    float pivot = ppw[left];

    while (left < right) {
        while (left<right && ppw[left] >= pivot)    ++left;
        while (left<right && ppw[right] < pivot)    --right;

        if (left < right) {
            swapi(&id[left], &id[right]);
            swapf(&ppw[left], &ppw[right]);
            swapf(&profit[left], &profit[right]);
            swapf(&weight[left], &weight[right]);
            ++left; --right;
        }
    }
    swapi(&id[low], &id[right]);
    swapf(&ppw[low], &ppw[right]);
    swapf(&profit[low], &profit[right]);
    swapf(&weight[low], &weight[right]);

    return right;
}

void sort (int* id, float* profit, float* weight, float* ppw, int low, int high) {       // quick sort
    if (low < high) {
        int pivot = partition(id, profit, weight, ppw, low, high);
        sort(id, profit, weight, ppw, low, pivot-1);
        sort(id, profit, weight, ppw, pivot+1, high);
    }
}

int main() {
    int n, capacity;
    int *id;
    float *profit, *weight, *ppw;
    int current_capacity = 0;
    float total_profit = 0, fraction;
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    id = (int *) malloc (sizeof(int)*n);

    profit = (float *) malloc (sizeof(float)*n);
    weight = (float *) malloc (sizeof(float)*n);
    ppw = (float *) malloc (sizeof(float)*n);


    printf("Enter max capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("\nEnter values for every item\n\n");
    for (i=0; i<n; ++i) {
        id[i] = i+1;

        printf("Enter profit for item %d: ", i+1);
        scanf("%f", &profit[i]);

        printf("Enter weight for %d item: ", i+1);
        scanf("%f", &weight[i]);

        ppw[i] = profit[i] / weight[i];
        printf("\n");
    }

    sort(id, profit, weight, ppw, 0, n-1);
    
    i = 0;
    printf("\nThe following items will be taken in the knapsack: \n");
    while (current_capacity < capacity && i<n) {
        if (weight[i] + current_capacity <= capacity) {
            printf("\nItem %d full", id[i]);
            total_profit += profit[i];
            current_capacity += weight[i];
            if (weight[i] + current_capacity == capacity)  break;
        }
        else {
            fraction = (capacity-current_capacity)/weight[i];
            printf("\nItem %d %.2f", id[i], fraction);
            total_profit += profit[i] * fraction;
            break;
        }
        ++i;
    }

    printf("\nTotal profit: %.2f\n", total_profit);

    free(id);
    free(profit);
    free(weight);
    free(ppw);

    return 0;
}