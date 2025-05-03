#include<stdio.h>
#include<malloc.h>

typedef struct job {
    int id;
    int deadline;
    int profit;
} job;

int partition(job* jobList, int low, int high) {
    job temp;
    int left = low, right = high;
    int pivot = jobList[low].profit;

    while (left <= right) {
        while (left<=right && jobList[left].profit >= pivot) ++left;
        while (left<=right && jobList[right].profit < pivot) --right;

        if (left < right) {
            temp = jobList[left];
            jobList[left] = jobList[right];
            jobList[right] = temp;
        }
    }

    temp = jobList[low];
    jobList[low] = jobList[right];
    jobList[right] = temp;

    return right;
}

void sort (job* jobList, int low, int high) {           // quick sort
    int pivot;
    if (low < high) {
        pivot = partition(jobList, low, high);
        sort(jobList, low, pivot-1);
        sort(jobList, pivot+1, high);
    }
}

int main () {
    job *jobList, *solution;
    int n, max = 0, i, deadline, index, total_profit = 0;

    printf("Enter total number of jobs available: ");
    scanf("%d", &n);

    jobList = (job *) malloc (sizeof(job) *n);

    for (i=0; i<n; ++i) {
        jobList[i].id = i+1;
        printf("\nEnter profit for job %d: ", i+1);
        scanf("%d", &jobList[i].profit);

        printf("Enter deadline for job %d: ", i+1);
        scanf("%d", &jobList[i].deadline);

        if (max < jobList[i].deadline)  max = jobList[i].deadline;
    }

    solution = (job *) malloc (sizeof(job) *max);

    for (i=0; i<max; ++i) {
        solution[i].id = -1;            // initializing the solution list with empty jobs
    }

    sort(jobList, 0, n-1);

    printf("\n-------------after sorting-----------\n");
    for (i=0; i<n; ++i) {
        printf("%d  ", jobList[i].id);
    }

    for (i=0; i<n; ++i) {
        deadline = jobList[i].deadline;
        index = deadline-1;
        while (index >= 0) {
            if (solution[index].id == -1) {
                solution[index].id = jobList[i].id;
                solution[index].profit = jobList[i].profit;
                solution[index].deadline = jobList[i].deadline;
                total_profit += jobList[i].profit;
                break;
            }
            --index;
        }
    }

    printf("\nThe jobs that are picked are: \n");
    printf("\nTime\tJob\tProfit\tdeadline");
    for (i=0; i<max; ++i) {
        printf("\n%d\t%d\t%d\t%d", i+1, solution[i].id, solution[i].profit, solution[i].deadline);
    }

    printf("\nTotal profit: %d\n", total_profit);

    free(jobList);
    free(solution);
    return 0;
}