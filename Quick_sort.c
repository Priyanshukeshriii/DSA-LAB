#include <stdio.h>

int comparisons = 0;
int iterations = 0;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

// ✅ fixed: partition now RETURNS loc
int partition(int arr[], int left, int right, int loc, int n) {
    while (left < right) {
        comparisons++;

        if (loc == left) {
            if (arr[loc] > arr[right]) {
                int temp = arr[loc];
                arr[loc] = arr[right];
                arr[right] = temp;
                loc = right;
                left++;
            } else {
                right--;
            }
        } else if (loc == right) {
            if (arr[loc] < arr[left]) {
                int temp1 = arr[loc];
                arr[loc] = arr[left];
                arr[left] = temp1;
                loc = left;
                right--;
            } else {
                left++;
            }
        }
    }

    return loc; 
}

void quick_sort(int arr[], int left, int right, int n) {
    int loc;
    if (left < right) {
        iterations++;
        loc = partition(arr, left, right, left, n);

        printf("After iteration %d: ", iterations);
        printArray(arr, n);

        quick_sort(arr, left, loc - 1, n);
        quick_sort(arr, loc + 1, right, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    printArray(arr, n);

    quick_sort(arr, 0, n - 1, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    printf("\nTotal Iterations: %d", iterations);
    printf("\nTotal Comparisons: %d\n", comparisons);

    return 0;
}
