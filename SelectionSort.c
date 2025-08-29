//time complexcity is O(n^2) in best and worst case

#include<stdio.h>

int comparisons = 0;
int iterations = 0;


void printArray(int arr[] , int n){
    for(int i  = 0 ; i< n ; i++){
        printf("%d, " ,arr[i] );
    }
    printf("\n");
}

void selectionSort(int arr[] ,int n){
    for(int i =0 ; i< n; i++){
        iterations++;
        int small = arr[i];
        int indexOfSmall = i;
        //finding the small element and its index
        for (int j= i+1; j <n ; j++){
            comparisons++;
            if(small > arr[j]){
                small = arr[j];
                indexOfSmall = j ;
            }
        }
        // placing the index to its correct position
        while (indexOfSmall -1 >=0 && small < arr[indexOfSmall-1] )
        {
            arr[indexOfSmall] = arr[indexOfSmall -1];
            indexOfSmall--;
        }
        arr[indexOfSmall] = small;
        
        //printing the element after every pass
        printf("pass %d: " ,iterations);
        printArray(arr , n);
        

    }
}

int main(){
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

    selectionSort(arr , n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    printf("\nTotal Iterations: %d", iterations);
    printf("\nTotal Comparisons: %d\n", comparisons);
}